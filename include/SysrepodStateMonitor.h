#pragma once

#include <thread>

#include "FormData.h"

class SysrepodStateMonitor {

public:
  explicit SysrepodStateMonitor(FormDataPtr formDataPtr);
  virtual ~SysrepodStateMonitor();

  void run()
  {
    thread_ = std::thread(&SysrepodStateMonitor::monitorThread, this);
  }

  void monitorThread();

private:
  FormDataPtr formDataPtr_;
  bool stopThread_ = false;
  std::thread thread_;

};