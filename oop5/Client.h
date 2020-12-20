#pragma once

#include "IAccount.h"

class Client {
    bu::uuid uuid = bu::random_generator()();

    std::string name;
    std::string surname;

    std::string address = "unspecified";
    std::string passport = "unspecified";

    bool stranger = true;
public:
    Client(std::string name, std::string surname);

    void SetAddress(std::string address_);

    void SetPassport(const std::string& passport_);

    std::string GetPassport();

    std::string GetAddress();

    bool GetStranger();

    bu::uuid GetID();

    void GetClient();
};