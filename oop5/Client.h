#pragma once

#include <utility>

class Client {
    std::string name;
    std::string surname;
    std::string address = "unspecified";
    std::string passport = "unspecified";
public:
    Client(std::string name, std::string surname) : name(std::move(name)), surname(std::move(surname)) {}

    void SetAddress(std::string address_) {
        address = std::move(address_);
    }

    void SetPassport(const std::string& passport_) {
        if (!(passport_.find_first_not_of( "0123456789" ) == std::string::npos && passport_.length() == 6)) {
            throw InvalidInputException();
        }
        passport = passport_;
    }

    std::string GetPassport() {
        return passport;
    }

    std::string GetAddress() {
        return address;
    }

    void GetClient() {
        std::cout << "Name: " << name << ", Surname: " << surname << ", Address: " << address << ", Passport: " << passport;
    }
};