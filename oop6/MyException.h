#pragma once

#include <exception>

class EmployeeException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "An ordinary employee can't have subordinates";
    }
};

class TeamLeadException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "TeamLead can't have a leader";
    }
};

class SameEmployeeException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "The employee is already on the list";
    }
};

class TaskNameException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "The task with this name is already exists";
    }
};

class TaskExistenceException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "No such task";
    }
};

class WrongDayException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "You can't add it to day report";
    }
};