#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include "PasswordManager.h"
using namespace std;






string username;
string encryptedPassword;
string encrypt(string);
PasswordManager::PasswordManager() {
    username = "";
    encryptedPassword = "";
}
PasswordManager::PasswordManager(string name, string pwd) {
    username = name;
    encryptedPassword = pwd;
}
void PasswordManager::setUsername(string newName) {
    username = newName;
}
void PasswordManager::setEncryptedPassword(string newPwd) {
    encryptedPassword = newPwd;
}
string PasswordManager::getUsername() {return username;};
string PasswordManager::getEncryptedPassword() {return encryptedPassword;};

bool PasswordManager::setNewPassword(string newPwd) {
    if (meetsCriteria(newPwd)) {
        encryptedPassword = encrypt(newPwd);
        return true;
    }
    return false;
}
bool PasswordManager::authenticate(string s) {
    return (encryptedPassword.compare(encrypt(s)) == 0);
}



string password;
string PasswordManager::encrypt(string s) {
    string newEncrypted = "";
    for (int i = 0; i < s.length(); i++) {
        newEncrypted[i] = ((s[i] - 33) + 25) % 94 + 33;
    }
    return s;
}

bool PasswordManager::meetsCriteria(string s) {
    bool lenCheck = (s.length() >= 8);
    int upperCheck = 0;
    int lowerCheck = 0;
    int digitCheck = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isupper(s[i])) {
            upperCheck++;
        } else if (islower(s[i])) {
            lowerCheck++;
        } else if (isdigit(s[i])) {

        }
    }
    if (lenCheck && upperCheck >= 1 && lowerCheck >= 1 & digitCheck >= 1) {
        return true;
    }
    return false;
}

        


