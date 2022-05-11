#ifndef LOGINAPPFUNCIONS_H_INCLUDED
#define LOGINAPPFUNCIONS_H_INCLUDED

#include<string>

using namespace std;

void saveToFile(string data);

char displayMenu();

void getPassword(string& password);

void repeatPassword(string password, string& password2);

void strong_password_check(string& password);

#endif // LOGINAPPFUNCIONS_H_INCLUDED
