#include "../include/atm_system/client_utils.h"
#include "../include/atm_system/menu_utils.h"
#include <iostream>
using namespace std;

namespace atm_menu {

    void normalWithdraw() {
        int amount = 0;

        client_utils::printHeader("Normal Withdraw Screen");

        do {
            cout << "\nEnter an amount (multiple of 5's): ";
            cin >> amount;
        } while (amount <= 0 || amount % 5 != 0);

        client_utils::withdrawAmount(amount);

        menu_utils::pauseAndReturnToMenu();
    }
    
}