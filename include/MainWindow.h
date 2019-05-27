#pragma once

#include <QMainWindow>
#include <QStringListModel>

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

    /**
     * Slot called when installed modules has been read
     */
    void onInstalledModulesReady(const QStringList &modules_list);

private:
    void setup_signals();

    Ui::MainWindow *ui_;
    FormDataPtr form_data_ptr_;
    SysrepoViewer sysrepo_viewer_;
    QStringListModel installed_modules_model_;
};