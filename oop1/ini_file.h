#include "ini_builder.h"

class IniFile {
    map<string, map<string, string>> ini_data;
    void set(string &section, string &key, string &value);
public:
    IniFile()=default;
    explicit IniFile(const map<string, map<string, string>> &ini_data);

    string get_string(string &section, string &key);
    float get_float(string &section, string &key);
    int get_int(string &section, string &key);
    IniFile parse(string &path);
};