#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include "PasswordManager.h"
using namespace std;



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
    // cout << "authenticating" << endl;
    // cout << encrypt(s) << endl;
    // cout << encryptedPassword << endl;
    return (encryptedPassword.compare(encrypt(s)) == 0);
}

string PasswordManager::encrypt(string s) {
   
    for (int i = 0; i < s.length(); i++) {
        s[i] = ((s[i] - 33) + 25) % 94 + 33;
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
            digitCheck++;
        }
    }
    // cout << "in meetscriteria" << endl;
    // cout << "len" << lenCheck << "  upper" << upperCheck << "  lower" << lowerCheck << "  digit" << digitCheck << endl;
    if (lenCheck && upperCheck >= 1 && lowerCheck >= 1 & digitCheck >= 1) {
        return true;
    }
    return false;
}

        


