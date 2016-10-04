#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;

void usage();
void about();
void version();
bool checkSpanish();


int main(int argc, char *args[]) {
    
    const int MAXPORT = 65535;
    string flag = "";
    string envFlag = "";
    const char* envName;

    
    if (argc == 1) {
         usage();
         return 0;
    }
    
   

    if (argc == 2) {
        flag = args[1];
        if (flag == "-h" || flag == "--help" || flag == "-?") {
        usage();
        return 0;
        }
    }
    
    if (argc == 2) {
        flag = args[1];
        if (flag == "-!" || flag == "--about") {
        about();
        return 0;
        }
    }
    
    if (argc == 2) {
        flag = args[1];
        if (flag == "-v" || flag == "--version") {
        version();
        return 0;
        }
    }

    if (argc == 2) {
        flag = args[1];
        if (flag != "-p" && flag != "--port" & flag != "-h" && flag != "--help") {
            if(checkSpanish()) {
                cout << "!Camino de comando no es válido!" << endl;
            } else {
        cout << "Invalid Command Path!" << endl;
        return 1;
        }
    }
    }
    
    if (argc > 2) {
        flag = args[1];
        envFlag = args[2];
        envName = args[3];
        
        if (flag == "-p" || flag == "--port") {
            if (envFlag == "-e") {
                 if (const char* envName = getenv("PORT")) {
                    if (checkSpanish()) { 
                        cout << "EL PORTE es: " << envName << endl;
                    }
                    else { 
                        cout << "Your PORT is: " << envName << endl;
                    }
                    return 0;
                }
                
            }
        }
    }
    
    if (argc == 3) {
        flag = args[1];
        if (flag != "-p" && flag != "--port" && flag != "-h" && flag != "--help") {
             if(checkSpanish()) {
                cout << "!Camino de comando no es válido!" << endl;
            }
        else {
        cout << "Invalid Command Path!" << endl;
        }
        return 1;
        }

    }
    
    
    if (argc == 4) {
        flag = args[1];
        envFlag = args[2];
        const char* envToken = args[3];
        if (flag == "-p" || flag == "--port") {
            if (envFlag == "-e") {
                if (const char* envFind = getenv(envToken)) {
                    if (checkSpanish()) { 
                        cout << "EL PORTE es: " << envFind << endl;
                    }
                    else { 
                        cout << "Your PORT is: " << envFind << endl;
                    }
                    return 0;
                }
            }
        }
    }
    
    if (flag == "-h" || flag == "--help") {
        usage();
        return 0;
    }
    
        if (argc == 2) {
            flag = args[1];
            if (flag == "-p" || flag == "--port") {
                if (checkSpanish()) {
                    cout << "!No se escucha ningun porte!" << endl;
                }
                else {
                    cout << "No port listening at this time." << endl;
                }
            return 0;
        }
    }
        
        try {
            if (stoi(args[2]) > 0 && stoi(args[2]) < MAXPORT) {
                if (checkSpanish()) {
                    cout << "Se eschuca el porte: " << args[2] << endl;
                }
                else {
                cout << "Listening on Port: " << args[2] << endl;
                }
                return 0;
            }
                if (stoi(args[2]) < 0 || stoi(args[2]) > MAXPORT) {
                    if (checkSpanish()) {
                        cout << "!Porte Invalido!" << endl;
                    }
                    else {
                    cout << "Invalid Port!" << endl;
                    }
                    return 1;
                }
                if (argc >= 2) {
                    string envVariable;
                    envVariable = args[2];
                    if (envVariable == "-e") {
                        return 0;
                    }
                }
        }
        catch (...) {
            cout << "This is not a port number!" << endl;
            return 1;
        }
    
    
    if (flag != "-p" || flag != "--port" || flag != "-h" || flag != "--help") {
        if (checkSpanish()) {
            cout << "!Camino de comando no es válido!" << endl;
        }
        else {
        cout << "Invalid Command Path!" << endl;
        }
        return 1;
    }
    
    }
    
    void usage() {
        string textLine; 
        string esTextLine;
        fstream esFileStream;
        fstream fileStream;
       
       fileStream.open("/home/ubuntu/workspace/portsetter.usage_en.txt");
       esFileStream.open("/home/ubuntu/workspace/portsetter.usage_es.txt");
       
       if (checkSpanish()) {
           if (esFileStream.is_open()) {
       while(getline (esFileStream, esTextLine)) {
           cout << esTextLine << endl;
       }
       esFileStream.close();
    }
    else cout << "!El archivo no se puede abrir!!!!" << endl;
    } else if (fileStream.is_open()) {
       while(getline (fileStream, textLine)) {
           cout << textLine << endl;
       }
       fileStream.close();
    }
    else cout << "File cannot open!" << endl;
    }
     
       
       
    
    void about() {
        string textLine;
        string esTextLine;
        fstream esFileStream;
       fstream fileStream;
       
       esFileStream.open("/home/ubuntu/workspace/portsetter.about_es.txt");
       fileStream.open("/home/ubuntu/workspace/portsetter.about_en.txt");
       
       if (checkSpanish()) {
           if (esFileStream.is_open()) {
       while(getline (esFileStream, esTextLine)) {
           cout << esTextLine << endl;
       }
       esFileStream.close();
       }
       else cout << "!El archivo no se puede abrir!!!!!" << endl;
       } else if (fileStream.is_open()) {
       while (getline (fileStream, textLine)) {
           cout << textLine << endl;
       }
       fileStream.close();
    }
    else cout << "File cannot open!" << endl;
    }
    
    void version() {
        
        string enStr = "This is Portsetter Version 3.";
        string esStr = "Esta es el programa Portsetter Version Tres.";
        
        if (checkSpanish()) {
            cout << esStr << endl;
        }
        else {
            cout << enStr << endl;
        }
    
        }
    
    
    bool checkSpanish() {
        
    string strOne = getenv("LANGUAGE");
    string strTwo = getenv("LC_ALL");
    string strThree = getenv("LC_MESSAGES");
    string strFour = getenv("LANG");
    
        for (int i = 0; i < strOne.length() - 1; i++) {
            
            if ((strOne[i] == 'e' || strOne[i] == 'E') && (strOne[i + 1] == 's' || strOne[i + 1] == 'S')) {
                return true;
            }
        }
        
        for (int i = 0; i < strTwo.length() - 1; i++) {
            
            if ((strTwo[i] == 'e' || strTwo[i] == 'E') && (strTwo[i + 1] == 's' || strTwo[i + 1] == 'S')) {
                return true;
            }
        }
        
        for (int i = 0; i < strThree.length() - 1; i++) {
            
            if ((strThree[i] == 'e' || strThree[i] == 'E') && (strThree[i + 1] == 's' || strThree[i + 1] == 'S')) {
                return true;
            }
        }
        
        for (int i = 0; i < strFour.length() - 1; i++) {
            
            if ((strFour[i] == 'e' || strFour[i] == 'E') && (strFour[i + 1] == 's' || strFour[i + 1] == 'S')) {
                return true;
            }
        }
        
        for (int i = 0; i < strOne.length() - 1; i++) {
            
            if ((strOne[i] == 'f' || strOne[i] == 'F') && (strOne[i + 1] == 'r' || strOne[i + 1] == 'R') || (strOne[i] == 'p' || strOne[i] == 'P') && (strOne[i + 1] == 'l' || strOne[i + 1] == 'L')) {
                cout << "No language files for this input!" << endl;
                return false;
            }
        }
        
        for (int i = 0; i < strTwo.length() - 1; i++) {
            
            if ((strTwo[i] == 'f' || strTwo[i] == 'F') && (strTwo[i + 1] == 'r' || strTwo[i + 1] == 'R') || (strTwo[i] == 'p' || strTwo[i] == 'P') && (strTwo[i + 1] == 'l' || strTwo[i + 1] == 'L')) {
                cout << "No language files for this input!" << endl;
                return false;
            }
        }
        
        for (int i = 0; i < strThree.length() - 1; i++) {
            
            if ((strThree[i] == 'f' || strThree[i] == 'F') && (strThree[i + 1] == 'r' || strThree[i + 1] == 'R') || (strThree[i] == 'p' || strThree[i] == 'P') && (strThree[i + 1] == 'l' || strThree[i + 1] == 'L')) {
                cout << "No language files for this input!" << endl;
                return false;
            }
        }
        
        for (int i = 0; i < strFour.length() - 1; i++) {
            
            if ((strFour[i] == 'f' || strFour[i] == 'F') && (strFour[i + 1] == 'r' || strFour[i + 1] == 'R') || (strFour[i] == 'p' || strFour[i] == 'P') && (strFour[i + 1] == 'l' || strFour[i + 1] == 'L')) {
                cout << "No language files for this input!" << endl;
                return false;
            }
        }
        return false;
        
        
    }