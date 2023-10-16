#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <PasswordManager.h>
using namespace std;




class PasswordManager {
    public:
        string username;
        string EncryptedPassword;
        PasswordManager::PasswordManager(string name, string pwd) {
            username = name;
            EncryptedPassword = pwd;
        }
        void PasswordManager::setUsername(string newName) {
            username = newName;
        }
        void setEncryptedPassword(string newPwd) {
            EncryptedPassword = newPwd;
        }
        string getUsername() const {return username;};
        string getEncryptedPassword() const {return EncryptedPassword;};

        void setNewPassword(string newPwd) {
            EncryptedPassword = encrypt(newPwd);
        }
        bool authenticate(string);


    private:
        string password;
        string encrypt(string s) {
            string newEncrypted = "";
            for (int i = 0; i < s.length(); i++) {
                newEncrypted[i] = ((s[i] - 33) + 25) % 94 + 33;
            }
            return s;
        }

        bool meetsCriteria(string s) {
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

        
};

