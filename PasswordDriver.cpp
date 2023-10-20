#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include "PasswordManager.h"
using namespace std;

void initArr(PasswordManager*);
void printCriteria();
void getInput(PasswordManager*);
int main(){
    
    //init array
    PasswordManager* arrPtr;
    arrPtr = new PasswordManager[3];
    PasswordManager* cur = arrPtr;

     
    //read and store from txt
    initArr(arrPtr);
  
    //print out the criteria
    printCriteria();

    //getInput and change password
    getInput(arrPtr);

    return 0 ;
}

void initArr(PasswordManager* arrPtr) {
    //open txt for input
    ifstream inputFile;
    inputFile.open("passwords.txt");
    //handle exception
    if (!inputFile.is_open()) {
        cerr << "Input file does not exist" << endl;
    }
    PasswordManager* cur = arrPtr;
    string line = "";
    while(getline(inputFile, line)) {
        size_t space = line.find(" ");
        string username = line.substr(0, space);
        string pwd = line.substr(space + 1);
        cout << username << endl;
        cout << pwd << endl;
        cur->setUsername(username);
        cur->setEncryptedPassword(pwd);  
        cur++;
    }
    inputFile.close();
}

void printCriteria() {
    cout << "Password Criteria" << endl;
    cout << "1. it is at least 8 characters long" << endl;
    cout << "2. it contains at least one uppercase letter" << endl;
    cout << "3. it contains at least one lowercase letter" << endl;
    cout << "4. it contains at least one digit" << endl;
    return;
}

void getInput(PasswordManager* arrPtr) {
    PasswordManager* cur = arrPtr;
    string name, pwd, newPwd;
    bool userNameValid = false;
    bool oldPwdValid = false;
    bool newPwdValid = false;
    cout << "Please enter your username: ";
    cin >> name;
    cout << "\nPlease enter your old password: ";
    cin >> pwd;
    cout << "\nPlease enter your new password: ";
    cin >> newPwd;
    for (int i = 0; i < 3; i++) {
        if (name.compare(cur->getUsername()) == 0) {
            userNameValid = true;
            if (cur->authenticate(pwd)) {
                oldPwdValid = true;
                if (cur->setNewPassword(newPwd) == true) {
                    newPwdValid = true;
                    cout << "Password has been changed for username: ";
                    cout << cur->getUsername() << endl;
                    break;
                }
            } 
        } 
        cur++;
    }
    if (!userNameValid) {
        cerr << "Username is invalid, password not changed." << endl;
    } else if (!oldPwdValid) {
        cerr << "Old password is incorrect." << endl;
    } else if (!newPwdValid) {
        cerr << "New password does not meet criteria." << endl;
    }
    return;

}