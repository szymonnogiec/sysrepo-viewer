#pragma once

#include <thread>

#include "FormData.h"

class SysrepodStateMonitor
{
public:
    explicit SysrepodStateMonitor(FormDataPtr formDataPtr);
    virtual ~SysrepodStateMonitor();

    void run()
    {
        thread_ = std::thread(&SysrepodStateMonitor::monitor_thread, this);
    }

    void monitor_thread();

private:
    FormDataPtr form_data_ptr_;
    bool stop_thread_ = false;
    std::thread thread_;

};