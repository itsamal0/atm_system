#include "../include/atm_system/client_utils.h"
#include "../include/atm_system/menu_utils.h"
#include "../include/atm_system/identity.h"
#include "../include/helpers//io_utils.h"
#include <iostream>
using namespace std;

namespace atm_menu {

    void checkBalance() {
        client_utils::printHeader("Check Balance Screen");

        cout << "\nYour Balance is " << identity::currentClient.accountBalance << endl;

        menu_utils::pauseAndReturnToMenu();
    }
    
}