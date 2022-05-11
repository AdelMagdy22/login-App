#ifndef LOGINAPPFUNCIONS_H_INCLUDED
#define LOGINAPPFUNCIONS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <regex>


using namespace std;

char displayMenu();

void saveToFile(string data);

string hidePassword(string& password);

void getPassword(string& password);

void repeatPassword(string password, string& password2);

void strong_password_check(string& password);

#endif // LOGINAPPFUNCIONS_H_INCLUDED
