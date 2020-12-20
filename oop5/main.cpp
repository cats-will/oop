#include <iostream>

#include "DebitAccount.h"
#include "Deposit.h"
#include "CreditAccount.h"
#include "Client.h"
#include "Bank.h"

int main() {
    boost::gregorian::date date(2020, 11, 8);
    IAccount *dep = new Deposit(100000, date);
    IAccount *cre = new CreditAccount(30000, 2, 50000);
    IAccount *deb = new DebitAccount(4000, 1, date);

/*
    std::cout << "balance: " << deb->GetBalance() << '\n';
    dep->TransferMoney(deb, 30);
    std::cout << "balance: " << deb->GetBalance() << '\n';
    deb->WithdrawMoney(200);
    std::cout << "balance: " << deb->GetBalance() << '\n';
    deb->TopUp(44);
    std::cout << "balance: " << deb->GetBalance() << '\n';
//    cre->TransferMoney(cre, 900); //проверка на "ты дебил"
//    std::cout << "balance: " << deb->GetBalance() << '\n';
*/
    Client client1("Lox1", "Sasha");
    Client client2("Lox2", "Sasha");

    Bank bank;
    bank.AddNewClient(client1);
    bank.AddNewClient(client2);

    bank.AddAccount(client1, dep);

   // bank.Withdraw(client1, dep, 2000);




}



    /*
    Client client("Boris", "Moshka");
    float d = 123;
    client.SetPassport("123123");
    std::cout << client.GetPassport() << '\n';
    client.GetClient();


    std::vector<IAccount*> m;
    m.push_back(dep1);
    */





//    boost::gregorian::date date(2020, 11, 8);
//
//    Deposit db(1000, date);
    //std::cout << db.GetID() << '\n';

   // db.WithdrawMoney(1200);
//
//    std::cout << db.GetPercent() << '\n';

