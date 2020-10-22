#include "MyExceptions.h"

#include <map>
#include <fstream>
#include <iostream>

class IniBuilder {
    map<string, map<string, string>> ini_data;
public:
    IniBuilder() = default;
    void set(const string &section, const map<string, string> &keys);
    map<string, map<string, string>> get_data();
};