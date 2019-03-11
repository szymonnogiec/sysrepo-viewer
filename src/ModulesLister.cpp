
#include <include/ModulesLister.h>

#include "ModulesLister.h"

sysrepo::ModuleLister::ModuleLister()
{
}

void sysrepo::ModuleLister::read_installed_modules()
{
    create_session();
    try {
        auto schemas = session_->list_schemas();
        for (size_t i = 0; i < schemas->schema_cnt(); ++i) {
            auto schema = schemas->schema(i);
            modules_.emplace_back(schema->module_name());
        }

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}


