
#include <include/MainWindow.h>

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow() :
    ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
    form_data_ptr_ = sysrepo_viewer_.get_form_data_ptr();
    sysrepo_viewer_.init();
    setup_signals();
    onSysrepodStateChanged(form_data_ptr_->is_sysrepod_running());
}

void MainWindow::setup_signals()
{
    // MainWindow/UI <-> SysrepoViewer
    connect(ui_->pb_send_, &QPushButton::clicked,
            &sysrepo_viewer_, &SysrepoViewer::onSendClicked);

    // MainWindow/UI
    connect(ui_->le_xpath_, &QLineEdit::textChanged,
            this, &MainWindow::onXpathChanged);

    //MainWindow <-> FormData
    connect(form_data_ptr_.get(), &FormData::sysrepodStateChanged,
            this, &MainWindow::onSysrepodStateChanged);
    connect(form_data_ptr_.get(), &FormData::installed_modules_ready,
            this, &MainWindow::onInstalledModulesReady);
}

void MainWindow::onXpathChanged(const QString &text)
{
    form_data_ptr_->xpath_ = text.toStdString();
}

void MainWindow::onSysrepodStateChanged(bool state)
{
    std::cout << "Changing sysrepod state to " << state << std::endl;
    ui_->l_sysrepod_state_->setText(state ? "Running" : "Not running");
    ui_->pb_connect_->setEnabled(state);
}

void MainWindow::onInstalledModulesReady(const QStringList &modules_list)
{
    ui_->lv_modules_->reset();
    installed_modules_model_.setStringList(modules_list);
    ui_->lv_modules_->setModel(&installed_modules_model_);
}

