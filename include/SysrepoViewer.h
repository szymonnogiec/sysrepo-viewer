#pragma once

#include <QObject>

#include "SysrepoConnector.h"
#include "FormData.h"

class SysrepoViewer : public QObject {
Q_OBJECT
public:
  SysrepoViewer();
  virtual ~SysrepoViewer() = default;

  const FormDataPtr &getFormDataPtr() const;

public slots:
  void onSendClicked();

private:
  SysrepoConnector sysrepoConnector_;
  FormDataPtr formDataPtr_;

};
