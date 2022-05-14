// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: login.cpp
// Last Modification Date: xx/xx/xxxx
// Author1 and ID and Group: Abdelrahman Tarek Mohamed   20210206
// Author2 and ID and Group: Adel Magdy Abd El-Hay       20210190
// Author3 and ID and Group: Roaa Talat Mohamed          20210138
// Teaching Assistant: Dr.Mohamed Al Ramly
// Purpose:..........




#include "loginAppFunc.h"
#include "loginAppFunc.cpp"

#define FILE_PATH "login.text"



int main()
{
    cout<<"Welcome to our login App.";
    loodExsitingUsers(NA, ID, PASS, GM, NO);
    char choice;
    while (true)
    {
        choice = displayMenu();
        if (choice == '1')
        {
            cout<<"Registering new user: \n";
            newuser();
        }else if(choice == '2')
        {
            cout<<"Log in: \n";
            int count = 0;    //      PUT   count = 0    IN  function main menu
            int size = 0;   //*(&users + 1) - users;
            login(NA,ID,PASS,size,count);
        }else if (choice == '3')
        {
            cout<<"Change password: \n";
            change_pass(NA,ID,PASS,GM,NO);
        }else
        {
            cout << "Thanks for using our App. \n" << endl;
            return 0;
        }
     }
}
