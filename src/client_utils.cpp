#include <iostream>
#include <fstream>
#include <limits>
#include "../include/atm_system/client_utils.h"
#include "../include/helpers/io_utils.h"
#include "../include/helpers/string_utils.h"
#include "../include/atm_system/identity.h"
using namespace std;
using namespace identity;

namespace client_utils {

    void printHeader(string headerText) {
        cout << "-------------------------------------\n";
        cout << "\t" << headerText << endl;
        cout << "-------------------------------------\n";
    }

    stClient readClientInput() {
        stClient loginAttempt;
        loginAttempt.accountNumber = io_utils::readString("\nEnter account number: ");
        loginAttempt.pinCode = io_utils::readString("\nEnter pin code: ");

        return loginAttempt;
    } 

       
    // Convert a line from file to a client struct
    stClient convertLineToRecord(string str, string separator) {
        stClient newClient;
        vector<string> vString = string_utils::splitString(str, separator);

        newClient.accountNumber  = vString[0];
        newClient.pinCode        = vString[1];
        newClient.name           = vString[2];
        newClient.phone          = vString[3];
        newClient.accountBalance = stod(vString[4]);

        return newClient;
    }

    // Convert a client struct to a single line string with separator
    string convertRecordToLine(stClient client, string separator) {
        string stClientRecord = "";
        stClientRecord += client.accountNumber + separator;
        stClientRecord += client.pinCode + separator;
        stClientRecord += client.name + separator;
        stClientRecord += client.phone + separator;
        stClientRecord += to_string(client.accountBalance);
        return stClientRecord;
    }


    // Load clients data from file into a vector
    vector<stClient> loadClientsDataFromFile(string fileName) {
        vector<stClient> vClients;
        fstream myFile;
        myFile.open(fileName, ios::in);

        if (myFile.is_open()) {
            string line;
            while (getline(myFile, line)) {
                vClients.push_back(convertLineToRecord(line));
            }
            myFile.close();
        }

        return vClients;
    }

    // Find a client by account number
    bool findClientByAccountNumber(const string& accountNumber, const vector<stClient>& vClients, stClient& client) {
        for (const stClient& c : vClients) {
            if (c.accountNumber == accountNumber) {
                client = c;
                return true;
            }
        }
        return false;
    }

    // Save all clients back to file
    vector<stClient> saveClientsDataToFile(const string& fileName, const vector<stClient>& vClients) {
        fstream myFile(fileName, ios::out);

        if (myFile.is_open()) {
            for (const stClient& c : vClients) {
                if (!c.markForDelete) {
                    myFile << convertRecordToLine(c) << endl;
                }
            }
            myFile.close();
        }

        return vClients;
    }

    void updateClient(string accountNumber, double newBalance) {
        vector<stClient> vClients = loadClientsDataFromFile(clientsFileName);

        // Update the client in the vector
        for (stClient& c : vClients) {
            if (c.accountNumber == accountNumber) {
                c.accountBalance = newBalance;
                break;
            }
        }
        // Save updated clients to file
        saveClientsDataToFile(clientsFileName, vClients);
    }

}