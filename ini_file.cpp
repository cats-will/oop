#include <regex>
#include "ini_file.h"

IniFile::IniFile(const map<string, map<string, string>> &ini_data) : ini_data(ini_data) {}

void IniFile::set(string &section, string &key, string &value) {
    ini_data[section][key] = value;
}

string IniFile::get_string(string &section, string &key) {
    if (ini_data.find(section) == ini_data.end()) {
        throw LossSectionException(-1);
    }

    map<string, string> &sec = ini_data[section];

    if(sec.find(key) == sec.end()) {
        throw LossKeyException(-2);
    }

    return sec[key];
}

float IniFile::get_float(string &section, string &key) {
    string value = get_string(section, key);
    try {
        return stof(value);
    } catch (WrongTypeException &ex) {
        cout << '\n' << "Error: " << ex.what() << '\n';
    }
}

int IniFile::get_int(string &section, string &key) {
    string value = get_string(section, key);
    try {
        return stoi(value);
    } catch (WrongTypeException &ex) {
        cout << '\n' << "Error: " << ex.what() << '\n';
    }
}

IniFile IniFile::parse(string &path) {

    if(path.size() > 4 && path.substr(path.size() - 4, 4) != ".ini") {
        throw WrongFormatException(-5);
    }

    try {
        ifstream fin(path);
    } catch (LossFileException &ex) {
        cout << '\n' << "Error: " << ex.what() << '\n';
    }

    ifstream fin(path);


    IniBuilder iniBuilder;

    string section, value;
    map<string, string> keys;

    regex sectionRegExp(R"(^\s*\[[a-zA-Z0-9_]+\]\s*(;.*)?)"); // what's the R
    regex KeyRegExp(R"(^\s*[a-zA-Z0-9_]+\s*=\s*[a-zA-Z0-9/\.]+\s*(;.*)?)");
    regex commentRegExp(R"(.*)");
    regex whiteSpaceString("\\s*");

    string buffer;

    while (!fin.eof()) {
        getline(fin, buffer);
        auto beginBuffer = buffer.begin();
        auto endBuffer = find(buffer.begin(), buffer.end(), ';');
        buffer = buffer.substr(distance(buffer.begin(), beginBuffer), distance(beginBuffer, endBuffer - 1));
        if(regex_match(buffer, sectionRegExp)) {
            if(!section.empty()) {
                iniBuilder.set(section, keys);
                keys.clear();
            }
            auto begin = find(buffer.begin(), buffer.end(), '[');
            auto end = find(buffer.begin(), buffer.end(), ']');
            section = buffer.substr(distance(buffer.begin(), begin + 1),distance(begin, end - 1));
        }
        else if (regex_match(buffer, KeyRegExp)) {
            buffer.erase(remove(buffer.begin(), buffer.end(), ' '), buffer.end());
            auto equal = find(buffer.begin(), buffer.end(), '=');
            value = buffer.substr(0UL, distance(buffer.begin(), equal));

            if(keys.find(value) != keys.end()) {
                throw RepeatedKeysException(-12);
            }

            auto comment = find(buffer.begin(), buffer.end(), ';');
            keys[value] = buffer.substr(distance(buffer.begin(), equal + 1), distance(equal, comment - 1));
        }
        else if (regex_match(buffer, commentRegExp) || regex_match(buffer, whiteSpaceString)) {
            continue;
        }
        else {
            throw InvalidFileException(-8);
        }
    }

    if (!keys.empty()) {
        iniBuilder.set(section, keys);
        keys.clear();
    }

    return IniFile(iniBuilder.get_data());
}





