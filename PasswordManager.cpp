// File Name: PasswordManager.cpp
//
// Authors: Zhiyuan Zhao, Regina Zhou
// Date: 10/20/2023
// Assignment Number 2
// CS 105C Fall 2023
// Instructor: Dr. Palacios
//
// A PasswordManager class with getters and setters, as well as
// methods for encryption and authentication.


#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include "PasswordManager.h"
using namespace std;


//author: Bryan & Regina
//encrpting the string using the provided Caesar Cipher algorithm
//returns the encrypted string
string PasswordManager::encrypt(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = ((s[i] - 33) + 25) % 94 + 33;
    }
    return s;
}

//author: Regina
//default constructor with no arguments, all variables initialized to empty
PasswordManager::PasswordManager() {
    username = "";
    encryptedPassword = "";
}

//author: Regina
//overloaded constructor with name and pwd parameters
PasswordManager::PasswordManager(string name, string pwd) {
    username = name;
    encryptedPassword = pwd;
}

//author: Regina
//set the username
void PasswordManager::setUsername(string newName) {
    username = newName;
}

//author: Regina
//set the encryptedPasswoard
void PasswordManager::setEncryptedPassword(string newPwd) {
    encryptedPassword = newPwd;
}

//author: Bryan
//return the username
string PasswordManager::getUsername() const {return username;};

//author: Bryan
//return the EncryptedPassword
string PasswordManager::getEncryptedPassword() const {return encryptedPassword;};

//author: Bryan & Regina
//check if the new pwd meets the conditions and then encrypt and update the pwd
//return true if modified and false otherwise
bool PasswordManager::setNewPassword(string newPwd) {
    if (meetsCriteria(newPwd)) {
        setEncryptedPassword(encrypt(newPwd));
        return true;
    }
    return false;
}

//author: Bryan
//check if the given pwd matches the encrypted pwd of this user
bool PasswordManager::authenticate(string s) {
    return (getEncryptedPassword().compare(encrypt(s)) == 0);
}
 //author: Bryan
 //Check for the 4 criteria using boolean flags, counters and for loops
bool PasswordManager::meetsCriteria(string s) {
    
    //init counters and flags
    bool lenCheck = (s.length() >= 8);
    int upperCheck = 0;
    int lowerCheck = 0;
    int digitCheck = 0;

    //loop through passwords
    for (int i = 0; i < s.length(); i++) {
        if (isupper(s[i])) {
            upperCheck++;
        } else if (islower(s[i])) {
            lowerCheck++;
        } else if (isdigit(s[i])) {
            digitCheck++;
        }
    }

    //check if all 4 conditon is met
    if (lenCheck && upperCheck >= 1 && lowerCheck >= 1 & digitCheck >= 1) {
        return true;
    }
    return false;
}

        


