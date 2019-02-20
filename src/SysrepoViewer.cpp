
#include <include/SysrepoViewer.h>

#include "SysrepoViewer.h"

void SysrepoViewer::onSendClicked() {
  auto sess = sysrepoConnector_.create_session();
  auto val = sess->get_item(formDataPtr_->xpath_.c_str());
  try {
    std::string val_string = val->val_to_string();
    std::cout << "Got val for xpath: " << val->xpath() << " : " <<
              val_string << std::endl;

  } catch (const sysrepo::sysrepo_exception &e) {
    std::cerr << e.what() << std::endl;
  }

}

const FormDataPtr &SysrepoViewer::getFormDataPtr() const {
  return formDataPtr_;
}

SysrepoViewer::SysrepoViewer() :
    formDataPtr_(new FormData) {
}
