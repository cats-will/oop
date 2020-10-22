#pragma once

//#include <bits/exception.h>
#include <string>
#include <exception>

using namespace std;

class InvalidFileException : public std::exception {
    int code_;
public:
    explicit InvalidFileException(int code);
    virtual const char* what() const throw();
    int code() const;
}; //-8

class WrongFormatException : public std::exception {
    int code_;
public:
    explicit WrongFormatException(int code);
    virtual const char* what() const throw();
    int code() const;
};//-5

class WrongTypeException : public std::exception {
    int code_;
public:
    explicit WrongTypeException(int code);
    virtual const char* what() const throw();
    int code() const;
};

class LossFileException : public std::exception {
    int code_;
public:
    explicit LossFileException(int code);
    virtual const char* what() const throw();
    int code() const;
};

class LossSectionException : public std::exception {
    int code_;
public:
    explicit LossSectionException(int code);
    virtual const char* what() const throw();
    int code() const;
};//-1

class RepeatedSectionException : public std::exception {
    int code_;
public:
    explicit RepeatedSectionException(int code);
    virtual const char* what() const throw();
    int code() const;
}; //-3

class LossKeyException : public std::exception {
    int code_;
public:
    explicit LossKeyException(int code);
    virtual const char* what() const throw();
    int code() const;
};//-2

class RepeatedKeysException : public std::exception {
    int code_;
public:
    explicit RepeatedKeysException(int code);
    virtual const char* what() const throw();
    int code() const;
}; //-12