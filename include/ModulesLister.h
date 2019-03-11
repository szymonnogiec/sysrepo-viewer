#pragma once

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

    void read_installed_modules();
private:
    std::vector<std::string> modules_;

};
}