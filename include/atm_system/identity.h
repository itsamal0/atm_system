#pragma once
#include <string>

namespace identity {

    struct stClient {
        std::string accountNumber;
        std::string pinCode;
        std::string name;
        std::string phone;
        double accountBalance;
        bool markForDelete = false;
    };

    extern stClient currentClient;

    bool login();
    bool auth(const stClient& loginAttempt);
}