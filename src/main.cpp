#include <iostream>
#include <vector>
#include "../include/atm_system/menu_utils.h"
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

        menu_utils::showMenu("ATM Main Menu Screen", mainMenuOptions);
        choice = menu_utils::readMenuChoice(1, mainMenuOptions.size());

        system("cls");

        switch (choice) {
            case QUICK_WITHDRAW:
                cout << "You chose Quick Withdraw.\n";
                break;
            case NORMAL_WITHDRAW:
                cout << "You chose Normal Withdraw.\n";
                break;
            case DEPOSIT:
                cout << "You chose Deposit.\n";
                break;
            case CHECK_BALANCE:
                cout << "You chose Check Balance.\n";
                break;
            case LOGOUT:
                cout << "Logging out...\n";
                break;
        }

        if (choice != LOGOUT) {
            cout << "\nPress any key to go back to main menu...";
            system("pause >nul");
        }

    } while (choice != LOGOUT);
}

void atmSystem() {
    showMainMenu();
}

int main() {
    system("cls");
    atmSystem();
    return 0;
}