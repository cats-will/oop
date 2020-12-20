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

class StrangerException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Transaction is denied, your address or passport are unspecified";
    }
};

class AlreadyExistException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "The client is already there";
    }
};

class StrangerLimitException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "You're over the limit, due to you're stranger, you can only use fix sum";
    }
};

class SenderDoesNotExistException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Sender doesn't exist";
    }
};

class ReceiverDoesNotExistException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Receiver doesn't exist";
    }
};

class WrongTimeException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "You entered incorrect time";
    }
};