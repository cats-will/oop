#pragma once

#include <list>
#include "Client.h"
#include "IAccount.h"
#include "Translations.h"

enum Time {
    DAY,
    MONTH,
    YEAR
};


class Bank {
    std::list<std::pair<Client, IAccount*>> ClientAccount;
    std::list<Client> ClientsWithoutAccounts;
    std::list<Translations> translations;
    float MaxStranger;
    float commission;
public:

    Bank() = default;

    Bank(std::list<std::pair<Client, IAccount*>> &ClientAccount_, float MaxStranger, float commission);

    void AddNewClient(Client &client);

    void AddAccount(Client &client, IAccount* account);

    void Withdraw(Bank &bank, Client &client, IAccount *which, float want);

    void TopUp(Client &client, IAccount *which, float add);

    void Transfer(IAccount *who, IAccount *whom, float _money);

    void ReturnTransfer(IAccount *who, IAccount *whom, float _money);

    float RewindTime(IAccount* account, Client &client, Time time);

    void SetLimitForStranger(float limit);

    std::list<std::pair<Client, IAccount*>> GetClientList();

    std::list<Client> GetClientsWithoutAccounts();
};