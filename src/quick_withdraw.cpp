#include "../include/atm_system/client_utils.h"
#include "../include/atm_system/identity.h"
#include "../include/atm_system/menu_utils.h"
#include <iostream>
using namespace std;
using namespace identity;

namespace atm_menu {
    enum enQuickWithdrawOptions {
        OPTION_20 = 1,
        OPTION_50,
        OPTION_100,
        OPTION_200,
        OPTION_400,
        OPTION_600,
        OPTION_800,
        OPTION_1000,
        EXIT
    };

    int getWithdrawAmount(enQuickWithdrawOptions option) {
        switch (option) {
       		case OPTION_20: return 20;
        	case OPTION_50: return 50;
        	case OPTION_100: return 100;
        	case OPTION_200: return 200;
        	case OPTION_400: return 400;
        	case OPTION_600: return 600;
        	case OPTION_800: return 800;
        	case OPTION_1000: return 1000;
        	default: return 0;
        }
    }

    void quickWithdraw() {
        int choice = 0;
        int amount = 0;

        client_utils::printHeader("Quick Withdraw Screen");

        cout << "       [1] 20        [2] 50" << endl;
        cout << "       [3] 100       [4] 200" << endl;
        cout << "       [5] 400       [6] 600" << endl;
        cout << "       [7] 800       [8] 1000" << endl;
        cout << "       [9] Exit" << endl;
        cout << "-------------------------------------\n";
        cout << "\nYour Balance is " << currentClient.accountBalance << endl;

        choice = menu_utils::readMenuChoice("\nChoose what to withdraw from [1] to [8]: ", 1, 9);
        
        if (choice == 9) {
            return;
        }

        amount = getWithdrawAmount((enQuickWithdrawOptions)choice);

        client_utils::applyTransaction(amount, "withdraw");

        menu_utils::pauseAndReturnToMenu();
    }
    
}