#include <iostream>
#include <fstream>
#include <string.h>
#include <regex>
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

void getPassword(string& password)
{
    cout <<"create a password (Use 8 or more characters using a combination of letters, numbers, and symbols) : ";
    getline(cin,password);
    while(password.length() < 8 )
    {
        cout<<"short password! Please enter again:";
        getline(cin,password);
    }
}

void repeatPassword(string password, string& password2)
{
    cout << "Re-Enter your password to confirm: ";
    getline(cin, password2);

    while (password2 != password)
    {
        cout <<"Passwords don't match! Please enter again: ";
        getline(cin, password2);
    }
    cout<<"Passwords match! \n";
}
void strong_password_check(string& password)
{
    const regex pattern("(?=.*[A-Z])(?=.*[\\d@$!%*#?&])(?=.*[A-Z\\d@$!%*#?&])[A-Za-z\\d@$!%*#?&]{8,}");
    while(!regex_search(password,pattern))
    {
        cout<<"week password! please enter again: ";
        getline(cin, password);
    }
    cout<<"strong password! \n";

    //pattern("(?=.*[A-Za-z])(?=.*\\d)(?=.*[@$!%*#?&])[A-Za-z\\d@$!%*#?&]{8,}$");
    //return regex_match(password,pattern);
}
