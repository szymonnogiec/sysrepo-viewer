#pragma once

#include <memory>
#include <mutex>

#include <QObject>

class FormData;
typedef std::shared_ptr<FormData> FormDataPtr;

/**
 * Class responsible for sharing data between backend and ui
 */
class FormData : public QObject
{
Q_OBJECT
public:
    FormData() = default;
    ~FormData() = default;
    std::string xpath_;

    bool is_sysrepod_running();
    void set_is_syrepod_running(bool is_sysrepod_running);

signals:
    /**
     * Signal emitted when sysrepo daemon changes state (from running to down or from down to up)
     * @param state New state of sysrepo daemon
     */
    void sysrepodStateChanged(bool state);

protected:
    bool is_sysrepod_running_ = false;

    std::mutex mutex_;
};