#include "loginAppFuncions.h"

using namespace std;

void saveToFile(string data)
{
    ofstream login;
    login.open("login.text", ios::app);
    login << data;
    login.close();
}

char displayMenu()
{
    char option;
    cout << "\nPlease select what you want to do:  " << endl;
    cout << "1- New User" << endl;
    cout << "0- Exit" << endl;
    cin>>option;
    return option;
}

// function to make password hide while the user is typing it.
string hidePassword(string& password){
    char pass[250];
    char ch;
    int i;
    for(i = 0;;) {
        ch = getch();
        // when user press enter "\n" to save the password
        if (ch == 13) {
            // assign last index in array of character
            pass[i] = '\0';
            password.assign(pass);
            cout << endl;
            return password;
        }
        else {
            if (ch == '\b' and i > 0) { // if user press backspace
                cout << "\b \b";
                i -= 1;
            }
            else {
                pass[i] = ch;
                i += 1;
                cout << '*';
            }
        }
    }
}

void getPassword(string& password)
{
    cout <<"create a password (Use 8 or more characters using a combination of letters, numbers, and symbols) : ";
    password = hidePassword(password);
    while(password.length() < 8 )
    {
        cout<<"short password! Please enter again:";
        password = hidePassword(password);
    }
}

void repeatPassword(string password, string& password2)
{
    cout << "Re-Enter your password to confirm: ";
    password2 = hidePassword(password);

    while (password2 != password)
    {
        cout <<"Passwords don't match! Please enter again: ";
        password2 = hidePassword(password);
    }
    cout<<"Passwords match! \n";
}
void strong_password_check(string& password)
{
    const regex pattern("(?=.*[A-Z])(?=.*[\\d@$!%*#?&])(?=.*[A-Z\\d@$!%*#?&])[A-Za-z\\d@$!%*#?&]{8,}");
    while(!regex_search(password,pattern))
    {
        cout<<"week password! please enter again: ";
        password = hidePassword(password);
    }
    cout<<"strong password! \n";

    //pattern("(?=.*[A-Za-z])(?=.*\\d)(?=.*[@$!%*#?&])[A-Za-z\\d@$!%*#?&]{8,}$");
    //return regex_match(password,pattern);
}
