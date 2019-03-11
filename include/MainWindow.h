#pragma once

#include <QMainWindow>

#include "SysrepoViewer.h"

namespace Ui
{
class MainWindow;
}

/**
 * Main window of the application
 */
class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    MainWindow();
    virtual ~MainWindow() {}

private slots:
    /**
     * Slot called when xpath value in the form line edit changed
     * @param text New text
     */
    void onXpathChanged(const QString &text);
    /**
     * Slot called when sysrepo daemon state changes
     * @param state New state of sysrepod
     */
    void onSysrepodStateChanged(bool state);

private:
    void setup_signals();

    Ui::MainWindow *ui_;
    FormDataPtr form_data_ptr_;
    SysrepoViewer sysrepo_viewer_;
};