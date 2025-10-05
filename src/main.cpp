#include <iostream>
#include <vector>
#include "../include/atm_system/menu_utils.h"
#include "../include/atm_system/identity.h"
#include "../include/atm_system/atm_menu.h"
using namespace std;

enum enMainMenuOptions {
    QUICK_WITHDRAW = 1,
    NORMAL_WITHDRAW,
    DEPOSIT,
    CHECK_BALANCE,
    LOGOUT,
};

vector<string> mainMenuOptions = {
    "Quick Withdraw",
    "Normal Withdraw",
    "Deposit",
    "Check Balance",
    "Logout"
};

void showMainMenu() {
    int choice = 0;

    do {
        system("cls");
        string mainMenuMsg = "\nChoose what do you want to do from [1] to [5]: ";

        menu_utils::showMenu("ATM Main Menu Screen", mainMenuOptions);
        choice = menu_utils::readMenuChoice(mainMenuMsg, 1, mainMenuOptions.size());

        system("cls");

        switch (choice) {
            case QUICK_WITHDRAW:
                atm_menu::quickWithdraw();
                break;
            case NORMAL_WITHDRAW:
                atm_menu::normalWithdraw();
                break;
            case DEPOSIT:
                atm_menu::deposit();
                break;
            case CHECK_BALANCE:
                atm_menu::checkBalance();
                break;
            case LOGOUT:
                return;
        }

    } while (true);
}

void atmSystem() {
    while (true) {
        system("cls");
        if (identity::login()) {
            showMainMenu();
        }
    }
}

int main() {
    atmSystem();
    return 0;
}