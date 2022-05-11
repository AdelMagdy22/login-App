// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: login.cpp
// Last Modification Date: xx/xx/xxxx
// Author1 and ID and Group: Abdelrahman Tarek Mohamed   20210206
// Author2 and ID and Group: Adel Magdy Abd El-Hay       20210190
// Author3 and ID and Group: Roaa Talat Mohamed          20210138
// Teaching Assistant: Dr.Mohamed Al Ramly
// Purpose:..........


#include <iostream>
#include <fstream>
#include <string.h>
#include <regex>
#include "loginAppFuncions.h"
using namespace std;

void newuser();

int main()
{
    cout<<"Welcome to our login App.";
    char choice = ' ';
    while (choice != '0')
    {
        choice = displayMenu();
        if (choice == '1')
        {
            newuser();
        } else
        {
            cout << "Thanks for using our App. \n" << endl;
            return 0;
        }
     }
     return 0;
}


bool Email_check(string email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email,pattern);
}

bool phone_check(string phone)
{
    const regex pattern("01[0125][0-9]{8}");
    return regex_match(phone,pattern);
}

bool username_check(string username)
{
    const regex pattern("[a-zA-Z0-9- ]+");
    return regex_match(username,pattern);
}


void newuser(){

    string x = "User name";
    char username[30];
    string password = " ";
    string password2 = " ";
    //char newemail[127];
    char email[127];
    char phone[11];

    while(x == "User name"){
        cin.ignore();
        cout <<"create a username: ";
        cin.getline(username,30);
        if(username_check(username))
        {
            cout <<"username created successfully"<<endl;
            saveToFile("\n");
            saveToFile(username);
            saveToFile(" ");
            x = "Password";
        }
        else
            cout<<" invalid username "<<endl;
    }


    while (x == "Password")
    {

        getPassword(password);
        strong_password_check(password);
        repeatPassword(password, password2);

        x = "Email";
    }

    saveToFile(password);
    saveToFile(" ");

    while (x == "Email"){
        cout<<"create an email: ";
        cin.getline(email,127);
        if(Email_check(email))
        {
            cout <<"email created successfully"<<endl;
            saveToFile(email);
            saveToFile(" ");
            x = "Phone";
        }
        else
            cout<<" invalid email"<<endl;

    }
    while (x == "Phone"){
        cout <<"enter your phone number: ";
        cin>>phone;

        if(phone_check(phone))
        {
            cout << "right phone number \n";
            saveToFile(phone);
            saveToFile(" ");
            x = " ";
        }
        else
        {
            cout<<"invalid phone number"<<endl;
        }
    }





    /*login.open("login.text", ios::in );
    while(!login.eof())
    {
        login.getline(username, 30, '|');
        login.getline(password, 30, '|');
        login.getline(newemail , 64);
        if(strcmp(newemail, email)==0)
        {
            cout <<"This email already exists, try another one"<<endl;
            break;
        }else
        {
            login << ;
        }
    }*/

}

