#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;

class PasswordManager {
    public:
        string username;
        string EncryptedPassword;
        PasswordManager(string, string);
        void setUsername(string);
        void setEncryptedPassword(string);
        string getUsername() const {return username;};
        string getEncryptedPassword() const {return EncryptedPassword;};
        void setNewPassword(string);
        bool authenticate(string);


    private:
        string password;
        string encrypt(string);
        bool meetsCriteria(string);

        
};