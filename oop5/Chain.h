#pragma once

#include <string>

#include "Bank.h"

class Handler {
public:
    virtual Handler *SetNext(Handler *handler) = 0; // построение цепочки
    virtual std::string Handle(Bank &bank, float howMuch) = 0; // выполнение запроса
};


class AbstractHandler : public Handler {
    Handler *next_handler;
public:
    AbstractHandler() : next_handler(nullptr) {}

    Handler *SetNext(Handler *handler) override {
        next_handler = handler;
        return handler;
    }

    std::string Handle(Bank &bank, float howMuch) override {
        if (next_handler) {
            return next_handler->Handle(bank, howMuch);
        }
        return {};
    }
};


class Stranger : public AbstractHandler {
    std::string Handle(Bank &bank, float howMuch) override {
        for(auto &it : bank.GetClientList()) {
            if (it.first.GetStranger()){
                throw StrangerException();
            }
            else {
                return AbstractHandler::Handle(bank, howMuch);
            }
        }
    }
};

class EnoughMoney : public AbstractHandler {
    std::string Handle(Bank &bank, float howMuch) override {
        for(auto &it : bank.GetClientList()) {
            if (it.second->GetBalance() < howMuch){
                throw NotEnoughMoneyException();
            }
            else {
                return AbstractHandler::Handle(bank, howMuch);
            }
        }
    }
};

