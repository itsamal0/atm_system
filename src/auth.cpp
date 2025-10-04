#include "../include/atm_system/identity.h"
#include "../include/atm_system/client_utils.h"
#include <iostream>
#include <vector>
using namespace std;

namespace identity {
    bool auth(const stClient &loginAttempt) {
        vector<stClient> vClients = client_utils::loadClientsDataFromFile(client_utils::clientsFileName);
        stClient foundClient;

        if (client_utils::findClientByAccountNumber(loginAttempt.accountNumber, vClients, foundClient)) {
            if (foundClient.pinCode == loginAttempt.pinCode) {
                currentClient = foundClient;
                return true;
            }
        }

        return false;
    }
}