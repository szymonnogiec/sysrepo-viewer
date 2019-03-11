
#include <include/Connector.h>

#include "Connector.h"

namespace sysrepo
{

Connector::Connector() :
    connection_(new sysrepo::Connection("sysrepo-viewer"))
{

}

sysrepo::S_Session Connector::create_session()
{
    session_ = std::make_shared<sysrepo::Session>(connection_, datastore_);
    return session_;
}
}