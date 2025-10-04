#include "../include/atm_system/identity.h"
#include "../include/atm_system/client_utils.h"
#include <iostream>
using namespace std;

namespace identity {
  bool login() {

    bool loginFaild = false;
    stClient loginAttempt;

    do {
      system("cls");
      client_utils::printHeader("Login Screen");

      if (loginFaild) {
        cout << "\nInvalid account number or pinCode, try again\n";
      }

      loginAttempt = client_utils::readClientInput();

      loginFaild = !auth(loginAttempt);

    } while (loginFaild);

    return true;
  }
}