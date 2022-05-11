#ifndef LOGINAPPFUNCIONS_H_INCLUDED
#define LOGINAPPFUNCIONS_H_INCLUDED

#include <string.h>
#include <conio.h>
#include <regex>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

void login(vector<string>n_a,vector<string>i_d,vector<string>p_s,int len,int count,string& password);
int CHECK_USRER_AND_PASS(string id ,string pass,vector<string>n_a,vector<string>i_d,vector<string>p_s,int len_c);
char displayMenu();
void saveToFile(string data);
string hidePassword(string& password);
void getPassword(string& password);
void repeatPassword(string password, string& password2);
void strong_password_check(string& password);

#endif // LOGINAPPFUNCIONS_H_INCLUDED
