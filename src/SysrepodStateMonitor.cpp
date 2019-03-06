#include "SysrepodStateMonitor.h"
#include <cstdlib>
#include <iostream>

SysrepodStateMonitor::SysrepodStateMonitor(FormDataPtr formDataPtr) :
    formDataPtr_(formDataPtr) {

}

SysrepodStateMonitor::~SysrepodStateMonitor() {
  stopThread_ = true;
  if(thread_.joinable()) thread_.join();
}

void SysrepodStateMonitor::monitorThread() {

  while(!stopThread_) {
    int rc = std::system("pidof sysrepod");
    std::cout << "RC of system pidof: " << rc << std::endl;
    bool isRunning =  rc == 0;
    if (isRunning != formDataPtr_->is_sysrepod_running())
      formDataPtr_->set_is_syrepod_running(isRunning);
    std::this_thread::sleep_for (std::chrono::seconds(1));
  }
}
