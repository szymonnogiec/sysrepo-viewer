#pragma once

#include <thread>

#include "FormData.h"

namespace sysrepo
{
/**
 * Class responsible for monitoring state of sysrepo engine
 * Runs in own thread
 */
class DaemonStateMonitor
{
public:
    explicit DaemonStateMonitor(FormDataPtr formDataPtr);
    virtual ~DaemonStateMonitor();

    void run()
    {
        thread_ = std::thread(&DaemonStateMonitor::monitor_thread, this);
    }

    void monitor_thread();

private:
    FormDataPtr form_data_ptr_;
    bool stop_thread_ = false;
    std::thread thread_;

};

}