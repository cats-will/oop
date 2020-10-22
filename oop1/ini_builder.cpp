#include "ini_builder.h"

void IniBuilder::set(const string &section, const map<string, string> &keys) {
    if(ini_data.find(section) != ini_data.end()) {
        throw RepeatedSectionException(-3);
    }
    ini_data.insert(make_pair(section, keys));
}

map<string, map<string, string>> IniBuilder::get_data() {
    return ini_data;
}