
#include <include/SysrepoConnector.h>

#include "SysrepoConnector.h"

SysrepoConnector::SysrepoConnector() :
connection_(new sysrepo::Connection("sysrepo-viewer")){

}

sysrepo::S_Session SysrepoConnector::create_session() {
    return std::make_shared<sysrepo::Session>(connection_, datastore_);
}
