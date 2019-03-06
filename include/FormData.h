#pragma once

#include <memory>
#include <mutex>

#include <QObject>

class FormData;
typedef std::shared_ptr<FormData> FormDataPtr;

class FormData : public QObject {
Q_OBJECT
public:
  FormData() = default;
  ~FormData() = default;
  std::string xpath_;

  bool is_sysrepod_running();
  void set_is_syrepod_running(bool is_sysrepod_running);

signals:
  void sysrepod_state_changed(bool state);

protected:
  bool is_sysrepod_running_ = false;

  std::mutex mutex_;
};