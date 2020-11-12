#pragma once

#include <exception>

class WrongTransportException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "WrongTransportException";
    }
};