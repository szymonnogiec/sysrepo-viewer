
#include <include/SysrepoViewer.h>

#include "SysrepoViewer.h"

void SysrepoViewer::onSendClicked()
{
    auto sess = sysrepo_connector_.create_session();
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
}

void SysrepoViewer::init()
{
    sysrepod_state_monitor_->run();
}
