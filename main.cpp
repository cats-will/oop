#include "ini_file.h"

int main() {
    IniFile iniFile;
    string path = "C:/Users/AStr/CLionProjects/qwertyuiop/file.ini";
    try {
        iniFile = IniFile().parse(path);
    } catch (std::exception &ex) {
        cout << '\n' << "Error: " << ex.what() ;
        return -22;
    }
    string name = "Settings";
    string archive = "Archive";
    cout << iniFile.get_int(name, archive);
}
