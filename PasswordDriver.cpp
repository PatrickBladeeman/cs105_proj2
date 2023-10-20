#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include "PasswordManager.h"
using namespace std;

void initArr(PasswordManager*);
void printCriteria();
int main(){
    
    //init array
    PasswordManager* arrPtr;
    arrPtr = new PasswordManager[3];
    PasswordManager* cur = arrPtr;

     
    //read and store from txt
    initArr(arrPtr);
  
    //print out the criteria
    printCriteria();

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
        // arrPtr[0].setEncryptedPassword(pwd);
        // arrPtr[0].setUsername(username);
        cout << "USERNAME HERE: " << cur->getUsername() << endl;
        cur++;
    }
}

void printCriteria() {
    cout << "Password Criteria" << endl;
    cout << "1. it is at least 8 characters long" << endl;
    cout << "2. it contains at least one uppercase letter" << endl;
    cout << "3. it contains at least one lowercase letter" << endl;
    cout << "4. it contains at least one digit" << endl;
    return;
}

void getInput() {

}