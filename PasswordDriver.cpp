// File Name: PasswordDriver.cpp
//
// Authors: Zhiyuan Zhao, Regina Zhou
// Date: 10/20/2023
// Assignment Number 2
// CS 105C Fall 2023
// Instructor: Dr. Palacios
//
// A PasswordDriver program for the PasswordManager class that 
// implements the change password utility.



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
void writeOutput(PasswordManager*);

//author: Bryan
//Main program that read and process the user inputs 
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

    //write new passwords to txt
    writeOutput(arrPtr);

    return 0 ;
}

//author: Bryan and Regina
//read inputs from txt file and initialize the 
//classes with the correct username and passwords
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
        cur->setUsername(username);
        cur->setEncryptedPassword(pwd);  
        cur++;
    }
    inputFile.close();
}

//author: regina
//print out the criteria
void printCriteria() {
    cout << "Password Criteria" << endl;
    cout << "1. it is at least 8 characters long" << endl;
    cout << "2. it contains at least one uppercase letter" << endl;
    cout << "3. it contains at least one lowercase letter" << endl;
    cout << "4. it contains at least one digit" << endl;
    return;
}

//author: Bryan
//gets user inputs for changing passwords and access
//the validity of the username, the old pwd and the new pwd
//print out the corresponding error message is invalid
void getInput(PasswordManager* arrPtr) {

    PasswordManager* cur = arrPtr;
    string name, pwd, newPwd;

    //boolean flags for error message
    bool userNameValid = false;
    bool oldPwdValid = false;
    bool newPwdValid = false;

    //grab user input
    cout << "Please enter your username: ";
    cin >> name;
    cout << "\nPlease enter your old password: ";
    cin >> pwd;
    cout << "\nPlease enter your new password: ";
    cin >> newPwd;

    //Nested if statements to check the 3 error conditions
    //break when valid
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
    //using the flags to print corresponding error message
    if (!userNameValid) {
        cerr << "Username is invalid, password not changed." << endl;
    } else if (!oldPwdValid) {
        cerr << "Old password is incorrect." << endl;
    } else if (!newPwdValid) {
        cerr << "New password does not meet criteria." << endl;
    }
    return;
}

//author: Regina
//write output to designated txt file
void writeOutput(PasswordManager* arrPtr) {
    PasswordManager* cur = arrPtr;
    ofstream outputFile;
    outputFile.open("passwords.txt");
    for (int i = 0; i < 3; i++) {
        outputFile << cur->getUsername() << " ";
        outputFile << cur->getEncryptedPassword() << endl;
        cur++;
    }
}