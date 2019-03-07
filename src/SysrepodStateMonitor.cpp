#include "SysrepodStateMonitor.h"
#include <cstdlib>
#include <iostream>

SysrepodStateMonitor::SysrepodStateMonitor(FormDataPtr formDataPtr) :
    form_data_ptr_(formDataPtr)
{

}

SysrepodStateMonitor::~SysrepodStateMonitor()
{
    stop_thread_ = true;
    if (thread_.joinable()) thread_.join();
}

void SysrepodStateMonitor::monitor_thread()
{

    while (!stop_thread_) {
        int rc = std::system("pidof sysrepod > /dev/null");
        bool isRunning = rc == 0;
        if (isRunning != form_data_ptr_->is_sysrepod_running())
            form_data_ptr_->set_is_syrepod_running(isRunning);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
