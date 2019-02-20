#pragma once

#include <QMainWindow>

#include "SysrepoViewer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT
public:
  MainWindow();
  virtual ~MainWindow() {}

private slots:
  void onXpathChanged(const QString &text);

private:
  void setupSignals();

  Ui::MainWindow *ui_;
  FormDataPtr formDataPtr_;
  SysrepoViewer sysrepoViewer_;
};