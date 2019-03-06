
#include <include/MainWindow.h>

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow() :
    ui_(new Ui::MainWindow) {
  ui_->setupUi(this);
  formDataPtr_ = sysrepoViewer_.getFormDataPtr();
  sysrepoViewer_.init();
  setupSignals();
  onSysrepodStateChanged(formDataPtr_->is_sysrepod_running());
}

void MainWindow::setupSignals() {
  connect(ui_->pb_send_, &QPushButton::clicked,
          &sysrepoViewer_, &SysrepoViewer::onSendClicked);
  connect(ui_->le_xpath_, &QLineEdit::textChanged,
          this, &MainWindow::onXpathChanged);
  connect(formDataPtr_.get(), &FormData::sysrepod_state_changed,
          this, &MainWindow::onSysrepodStateChanged);
}

void MainWindow::onXpathChanged(const QString &text) {
  formDataPtr_->xpath_ = text.toStdString();
}

void MainWindow::onSysrepodStateChanged(bool state) {
  std::cout << "Changing sysrepod state to " << state << std::endl;
  ui_->l_sysrepod_state_->setText(state ? "Running" : "Not running");
}

