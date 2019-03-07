#pragma once

#include <QObject>

#include "SysrepoConnector.h"
#include "FormData.h"
#include "SysrepodStateMonitor.h"

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
    SysrepoConnector sysrepo_connector_;
    FormDataPtr form_data_ptr_;
    std::shared_ptr<SysrepodStateMonitor> sysrepod_state_monitor_;

};
