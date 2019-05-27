
#include <include/SysrepoViewer.h>

#include "SysrepoViewer.h"

void SysrepoViewer::onSendClicked()
{
    auto sess = sysrepo_connector_.get_session();
    auto val = sess->get_item(form_data_ptr_->xpath_.c_str());
    try {
        std::string val_string = val->val_to_string();
        std::cout << "Got val for xpath: " << val->xpath() << " : " <<
                  val_string << std::endl;

    } catch (const sysrepo::sysrepo_exception &e) {
        std::cerr << e.what() << std::endl;
    }

}

const FormDataPtr &SysrepoViewer::get_form_data_ptr() const
{
    return form_data_ptr_;
}

SysrepoViewer::SysrepoViewer() :
    form_data_ptr_(new FormData),
    sysrepod_state_monitor_(std::make_shared<sysrepo::DaemonStateMonitor>(form_data_ptr_))
{
    connectors_.emplace_back(std::make_shared<sysrepo::Connector>(sysrepo_connector_));
    connectors_.emplace_back(std::make_shared<sysrepo::Connector>(modules_lister_));
}

void SysrepoViewer::init()
{
    setup_signals();
    sysrepod_state_monitor_->run();
}

void SysrepoViewer::onSysrepodStateChanged(bool running)
{
    if (running) {
        std::for_each(connectors_.begin(), connectors_.end(), [=]
            (std::shared_ptr<sysrepo::Connector> conn)
        {
            if(conn)
                conn->reconnect();
        });

        form_data_ptr_->set_installed_modules_model(
            modules_lister_.get_modules());
    }
}

void SysrepoViewer::setup_signals()
{
    connect(form_data_ptr_.get(), &FormData::sysrepodStateChanged,
            this, &SysrepoViewer::onSysrepodStateChanged);
}
