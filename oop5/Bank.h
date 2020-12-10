#pragma once

#include "Client.h"
#include "IAccount.h"

class Bank {
    std::vector<Client> clients;
    std::vector<IAccount*> accounts;
    bool stranger = false;
public:
};