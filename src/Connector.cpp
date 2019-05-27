
#include <include/Connector.h>

#include "Connector.h"

namespace sysrepo
{

Connector::Connector() :
    datastore_(SR_DS_RUNNING)
{
    init_connection();
}

sysrepo::S_Session Connector::get_session()
{
    return session_;
}

void Connector::init_connection()
{
    connection_ = std::make_shared<sysrepo::Connection>("sysrepo-viewer");
    session_ = std::make_shared<sysrepo::Session>(connection_, datastore_);
}

void Connector::reconnect()
{
    std::cout << "Reconnect" << std::endl;
    init_connection();
}

}