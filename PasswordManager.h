// File Name: PasswordManager.h
//
// Authors: Zhiyuan Zhao, Regina Zhou
// Date: 10/20/2023
// Assignment Number 2
// CS 105C Fall 2023
// Instructor: Dr. Palacios
//
// A PasswordManager .h header file that specifies the inplementation and 
// structure of the PasswordManager class.


#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H
using namespace std;

class PasswordManager {
    public:
        PasswordManager();
        PasswordManager(string, string);
        void setUsername(string);
        void setEncryptedPassword(string);
        string getUsername() const;
        string getEncryptedPassword() const;
        bool setNewPassword(string);
        bool authenticate(string);


    private:
        string username;
        string encryptedPassword;
        string encrypt(string);
        bool meetsCriteria(string);

        
};

#endif