
#include <include/FormData.h>

#include "FormData.h"

bool FormData::is_sysrepod_running()
{
    std::lock_guard<std::mutex> lock_guard(mutex_);
    return is_sysrepod_running_;
}

void FormData::set_is_syrepod_running(bool is_sysrepod_running)
{
    std::lock_guard<std::mutex> lock_guard(mutex_);
    if (is_sysrepod_running_ != is_sysrepod_running)
        emit sysrepodStateChanged(is_sysrepod_running);
    is_sysrepod_running_ = is_sysrepod_running;
}
