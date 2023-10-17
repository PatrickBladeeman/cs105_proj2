#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H
using namespace std;

class PasswordManager {
    public:
        string username;
        string EncryptedPassword;
        PasswordManager();
        PasswordManager(string, string);
        void setUsername(string);
        void setEncryptedPassword(string);
        string getUsername();
        string getEncryptedPassword();
        bool setNewPassword(string);
        bool authenticate(string);


    private:
        string password;
        string encrypt(string);
        bool meetsCriteria(string);

        
};

#endif