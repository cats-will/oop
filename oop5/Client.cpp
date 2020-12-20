#include "Client.h"

Client::Client(std::string name, std::string surname) : name(std::move(name)), surname(std::move(surname)) {}


void Client::SetAddress(std::string address_) {
    address = std::move(address_);
    if (passport == "unspecified") {
        stranger = true;
    }
    else {
        stranger = false;
    }
}


void Client::SetPassport(const std::string& passport_) {
    if (!(passport_.find_first_not_of( "0123456789" ) == std::string::npos && passport_.length() == 6)) {
        throw InvalidInputException();
    }
    passport = passport_;

    if (address == "unspecified") {
        stranger = true;
    }
    else {
        stranger = false;
    }
}


std::string Client::GetPassport() {
    return passport;
}


std::string Client::GetAddress() {
    return address;
}


bool Client::GetStranger() {
    return stranger;
}


bu::uuid Client::GetID()  {
    return uuid;
}


void Client::GetClient() {
    std::cout << "Name: " << name << ", Surname: " << surname << ", Address: " << address << ", Passport: " << passport;
}