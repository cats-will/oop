#include "Bank.h"

Bank::Bank(std::list<std::pair<Client, IAccount*>> &ClientAccount_, float MaxStranger, float commission) : ClientAccount(ClientAccount_), MaxStranger(MaxStranger), commission(commission) {}


void Bank::AddNewClient(Client &client) {

    for(auto &it : ClientsWithoutAccounts) {
        if(it.GetID() == client.GetID()) {
            throw AlreadyExistException();
        }
    }
    ClientsWithoutAccounts.emplace_back(client);
}


void Bank::AddAccount(Client &client, IAccount* account) {
    for (auto &it : ClientsWithoutAccounts) {
        if (it.GetID() == client.GetID()) {
            ClientAccount.emplace_back(it, account);
        }
    }
    for(auto item = ClientsWithoutAccounts.begin(); item != ClientsWithoutAccounts.end(); item++) {
        if (item->GetID() == client.GetID()) {
            ClientsWithoutAccounts.erase(item);
            break;
        }
    }
}


void Bank::Withdraw(Bank &bank, Client &client, IAccount *which, float want) {
    if (client.GetStranger() && want > MaxStranger) {
        throw StrangerLimitException();
    }

    for (auto &it : ClientAccount) {
        if (it.first.GetID() == client.GetID() && it.second->GetID() == which->GetID()) {
            which->WithdrawMoney(want);
        }
    }
}


void Bank::TopUp(Client &client, IAccount *which, float add) {
    for (auto &it : ClientAccount) {
        if (it.first.GetID() == client.GetID() && it.second->GetID() == which->GetID()) {
            which->TopUp(add);
        }
    }
}


void Bank::Transfer(IAccount *who, IAccount *whom, float _money) {

    Translations translation(who, whom, _money);
    translations.push_back(translation);

    for(auto &it : ClientAccount) {
        if (it.first.GetID() == who->GetID()) {
            if (it.first.GetID() == whom->GetID()) {
                // include chain somewhere here
                for(auto &item : ClientAccount) {
                    if (item.first.GetID() == who->GetID()) {
                        item.second->WithdrawMoney(_money);
                    }
                    if (item.first.GetID() == whom->GetID()) {
                        item.second->TopUp(_money);
                    }
                }
            }
            else {
                throw ReceiverDoesNotExistException();
            }
        }
        else {
            throw SenderDoesNotExistException();
        }
    }
}


void Bank::ReturnTransfer(IAccount *who, IAccount *whom, float _money) {
    for(auto item = translations.begin(); item != translations.end(); item++) {
        if (item->GetWho() == who && item->GetWhom() == whom && item->GetMoney() == _money) {
            translations.erase(item);

            who->TopUp(_money);
            whom->WithdrawMoney(_money);

            break;
        }
    }
}


float Bank::RewindTime(IAccount* account, Client &client, Time time) {
    float final_sum = 0;
    for(auto &it : ClientAccount) {
        if (it.first.GetID() == client.GetID() && it.second->GetID() == account->GetID()) {
            if (time == DAY) {
                final_sum += account->GetBalance() - commission / 30;
            } else if (time == MONTH) {
                final_sum += account->GetBalance() - commission;
            } else if (time == YEAR) {
                final_sum += account->GetBalance() - commission * 12;
            } else {
                throw WrongTimeException();
            }
        }
    }
    return final_sum;
}


void Bank::SetLimitForStranger(float limit) {
    MaxStranger = limit;
}


std::list<std::pair<Client, IAccount*>> Bank::GetClientList() {
    return ClientAccount;
}


std::list<Client> Bank::GetClientsWithoutAccounts() {
    return ClientsWithoutAccounts;
}