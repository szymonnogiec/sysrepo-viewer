#pragma once

#include <memory>
#include <mutex>

#include <QObject>
#include <QStringList>

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
    void set_installed_modules_model(const QStringList &installed_modules);

signals:
    /**
     * Signal emitted when sysrepo daemon changes state (from running to down or from down to up)
     * @param state New state of sysrepo daemon
     */
    void sysrepodStateChanged(bool state);

    void installed_modules_ready(const QStringList& modules_list);
protected:
    bool is_sysrepod_running_ = false;

    QStringList modules_list_;
    std::mutex mutex_;
};