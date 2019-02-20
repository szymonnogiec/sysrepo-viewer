
#include <include/MainWindow.h>

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow() :
    ui_(new Ui::MainWindow) {
  ui_->setupUi(this);
  formDataPtr_ = sysrepoViewer_.getFormDataPtr();
  setupSignals();
}

void MainWindow::setupSignals() {
  connect(ui_->pb_send_, &QPushButton::clicked,
          &sysrepoViewer_, &SysrepoViewer::onSendClicked);
  connect(ui_->le_xpath_, &QLineEdit::textChanged,
          this, &MainWindow::onXpathChanged);
}

void MainWindow::onXpathChanged(const QString &text) {
  formDataPtr_->xpath_ = text.toStdString();
}

