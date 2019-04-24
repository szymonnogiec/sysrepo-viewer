
#include <include/Connector.h>

#include "Connector.h"

namespace sysrepo
{

Connector::Connector()
{

}

sysrepo::S_Session Connector::create_session()
{
    init_connection();
    session_ = std::make_shared<sysrepo::Session>(connection_, datastore_);
    return session_;
}

void Connector::init_connection()
{
    if (connection_ == nullptr)
        connection_ = std::make_shared<sysrepo::Connection>("sysrepo-viewer");
}
}