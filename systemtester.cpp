#include <iostream>
using namespace std;

int main(int argc, char* args[]) {
    
    string stringToPass = "~/workspace/port.cpp.o";
    for (int i = 1; i < argc; ++i) {
        stringToPass += " ";
        stringToPass += args[i];
    }
    //char* charArrayToPass = stringToPass;
    //cout << stringToPass << endl;
    setenv("LANGUAGE","C",1);
    setenv("LC_ALL","fr",1);
    setenv("LC_MESSAGES","C-UTF.8",1);
    setenv("LANG","C",1);
    system(stringToPass.c_str());
    return 0;
}