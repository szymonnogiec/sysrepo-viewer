#pragma once

#include <QObject>

#include "ModulesLister.h"
#include "FormData.h"
#include "DaemonStateMonitor.h"

class SysrepoViewer : public QObject
{
Q_OBJECT
public:
    SysrepoViewer();
    virtual ~SysrepoViewer() = default;

    void init();
    const FormDataPtr &get_form_data_ptr() const;

public slots:
    void onSendClicked();
    /**
     * Slot called when sysrepod is detected to be/stop running
     */
    void onSysrepodStateChanged(bool running);

private:
    /**
     * Connect signals into slots
     */
    void setup_signals();

    std::vector<std::shared_ptr<sysrepo::Connector>> connectors_;
    sysrepo::Connector sysrepo_connector_;
    sysrepo::ModuleLister modules_lister_;
    FormDataPtr form_data_ptr_;
    std::shared_ptr<sysrepo::DaemonStateMonitor> sysrepod_state_monitor_;

};
