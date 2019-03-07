#pragma once

#include <QMainWindow>

#include "SysrepoViewer.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    MainWindow();
    virtual ~MainWindow() {}

private slots:
    void onXpathChanged(const QString &text);
    void onSysrepodStateChanged(bool state);

private:
    void setup_signals();

    Ui::MainWindow *ui_;
    FormDataPtr form_data_ptr_;
    SysrepoViewer sysrepo_viewer_;
};