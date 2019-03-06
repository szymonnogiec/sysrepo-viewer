#pragma once

#include <QObject>

#include "SysrepoConnector.h"
#include "FormData.h"
#include "SysrepodStateMonitor.h"

class SysrepoViewer : public QObject {
Q_OBJECT
public:
  SysrepoViewer();
  virtual ~SysrepoViewer() = default;

  void init();
  const FormDataPtr &getFormDataPtr() const;

public slots:
  void onSendClicked();

private:
  SysrepoConnector sysrepoConnector_;
  FormDataPtr formDataPtr_;
  std::shared_ptr<SysrepodStateMonitor> sysrepodStateMonitor_;

};
