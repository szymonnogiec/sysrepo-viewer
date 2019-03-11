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

private:
    sysrepo::Connector sysrepo_connector_;
    sysrepo::ModuleLister sysrepo_modules_lister_;
    FormDataPtr form_data_ptr_;
    std::shared_ptr<sysrepo::DaemonStateMonitor> sysrepod_state_monitor_;

};
