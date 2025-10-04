#pragma once
#include <string>
#include <vector>
#include "identity.h"

namespace client_utils {
    const std::string clientsFileName = "data/clients.txt";
    void printHeader(std::string headerText);
    identity::stClient readClientInput();
    identity::stClient convertLineToRecord(std::string str, std::string separator = "#//#");
    std::vector<identity::stClient> loadClientsDataFromFile(std::string fileName);
    bool findClientByAccountNumber(const std::string& accountNumber, const std::vector<identity::stClient>& vClients, identity::stClient& client);
}