#include "MyExceptions.h"

InvalidFileException::InvalidFileException(int code) : code_(code) {}
const char *InvalidFileException::what() const throw() {
    return "Invalid file" + code_;
}
int InvalidFileException::code() const {
    return code_;
}

WrongFormatException::WrongFormatException(int code) : code_(code) {}
const char *WrongFormatException::what() const throw() {
    return "Wrong format" + code_;
}
int WrongFormatException::code() const {
    return code_;
}

WrongTypeException::WrongTypeException(int code) : code_(code) {}
const char *WrongTypeException::what() const throw() {
    return "Wrong type" + code_;
}
int WrongTypeException::code() const {
    return code_;
}

LossSectionException::LossSectionException(int code) : code_(code) {}
const char *LossSectionException::what() const throw() {
    return "Loss section" + code_;
}
int LossSectionException::code() const {
    return code_;
}

LossKeyException::LossKeyException(int code) : code_(code) {}
const char *LossKeyException::what() const throw() {
    return "Loss key" + code_;
}
int LossKeyException::code() const {
    return code_;
}

RepeatedKeysException::RepeatedKeysException(int code) : code_(code) {}
const char *RepeatedKeysException::what() const throw() {
    return "Loss value" + code_;
}
int RepeatedKeysException::code() const {
    return code_;
}


RepeatedSectionException::RepeatedSectionException(int code) : code_(code) {}
const char *RepeatedSectionException::what() const throw() {
    return "There are 2 same sections" + code_;
}
int RepeatedSectionException::code() const {
    return code_;
}

LossFileException::LossFileException(int code) : code_(code) {}
const char *LossFileException::what() const throw() {
    return "Loss file" + code_;
}
int LossFileException::code() const {
    return code_;
}
