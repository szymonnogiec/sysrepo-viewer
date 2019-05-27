
#include <include/ModulesLister.h>

#include "ModulesLister.h"

sysrepo::ModuleLister::ModuleLister()
{
}

void sysrepo::ModuleLister::read_installed_modules()
{
    std::cout << "Reading installed modules" << std::endl;
    modules_.clear();
    try {
        auto schemas = session_->list_schemas();
        for (size_t i = 0; i < schemas->schema_cnt(); ++i) {
            auto schema = schemas->schema(i);
            modules_.push_back(schema->module_name());
        }
    }
    catch (const sysrepo_exception &e) {
        std::cerr << "Exception while getting schemas" << std::endl;
        std::cerr << e.what() << std::endl;
        reconnect();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

const QStringList &sysrepo::ModuleLister::get_modules()
{
    read_installed_modules();
    return modules_;
}
