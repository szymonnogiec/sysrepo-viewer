#pragma once

#include <QList>
#include <QString>

#include "Connector.h"

namespace sysrepo
{
/**
 * Class responsible for providing data about installed yang modules
 * from sysrepo
 */
class ModuleLister : public Connector
{
public:
    ModuleLister();
    virtual ~ModuleLister() = default;

    const QStringList &get_modules();

private:
    void read_installed_modules();

    QStringList modules_;
};
}