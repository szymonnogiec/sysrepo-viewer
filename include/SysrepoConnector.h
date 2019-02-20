#pragma once

#include <sysrepo-cpp/Session.hpp>

class SysrepoConnector {
public:
    SysrepoConnector();

    virtual ~SysrepoConnector() = default;

    sysrepo::S_Session create_session();

private:
    sysrepo::S_Connection connection_;
    sr_datastore_t datastore_;
};