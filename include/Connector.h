#pragma once

#include <sysrepo-cpp/Session.hpp>

namespace sysrepo
{
class Connector
{
public:
    Connector();
    virtual ~Connector() = default;

    void init_connection();
    sysrepo::S_Session create_session();

protected:
    sysrepo::S_Connection connection_;
    sysrepo::S_Session session_;
    sr_datastore_t datastore_;
};
}