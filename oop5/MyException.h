#pragma once

#include <exception>

class NotEnoughMoneyException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Output in the negative";
    }
};

class InvalidSumException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Invalid sum";
    }
};

class WithdrawException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "You can't withdraw money";
    }
};

class LimitException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "You're over the limit";
    }
};

class InvalidInputException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Incorrect data";
    }
};

class SelfTransferException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "No comments";
    }
};