#include "../include/atm_system/client_utils.h"
#include "../include/atm_system/menu_utils.h"
#include "../include/atm_system/identity.h"
#include "../include/helpers//io_utils.h"
#include <iostream>
using namespace std;

namespace atm_menu {

    void deposit() {
        client_utils::printHeader("Deposit Screen");

        cout << "\nYour Balance is " << identity::currentClient.accountBalance << endl;

        int amount = io_utils::readPositiveNumber("\nEnter a positive deposit amount: ");

        client_utils::applyTransaction(amount, "deposit");

        menu_utils::pauseAndReturnToMenu();
    }
    
}