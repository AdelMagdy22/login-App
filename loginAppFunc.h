#ifndef LOGINAPPFUNCIONS_H_INCLUDED
#define LOGINAPPFUNCIONS_H_INCLUDED
#define FILE_PATH "login.text"

#include <Windows.h>
#include <string.h>
#include <conio.h>
#include <regex>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include <ctime>
//#include <iomanip>

using namespace std;
vector<string> NA ;
vector<string> ID ;
vector<string> PASS ;
vector<string> GM ;
vector<string> NO ;



const int ConnectNormal = 0;
const int ConnectSSLAuto = 1;
const int ConnectSTARTTLS = 2;
const int ConnectDirectSSL = 3;
const int ConnectTryTLS = 4;

string railFence(string text, int base, string answer);
string hidePassword(string& password);
char displayMenu();
int CHECK_USRER_AND_PASS(string id ,string pass,vector<string>n_a,vector<string>i_d,vector<string>p_s,int len_c);
bool Email_check(string email);
bool phone_check(string phone);
bool username_check(string username);
bool ID_check(string ID);
void loodExsitingUsers(vector<string>& NA,vector<string>& ID,vector<string>& PASS,vector<string>& GM,vector<string>& NO );
void saveToFile(string data);
void newuser();
bool validateUsername(vector<string>& NA, string& username);
bool validateID(vector<string>& ID, string& I_D );
bool validateEmail(vector<string>g_m, const string& email);
void getPassword(string& password);
void getPassword_l(string& password);
void repeatPassword(string password, string& password2);
void strong_password_check(string& password);
void login(vector<string>n_a,vector<string>i_d,vector<string>p_s,int len,int count);
void change_pass(vector<string>n_m,vector<string>i_d,vector<string>p_s,vector<string>g_m,vector<string>n_o);
void save_new_pass(vector<string>n_m,vector<string>i_d,vector<string>p_s,vector<string>g_m,vector<string>n_o);



#endif // LOGINAPPFUNCIONS_H_INCLUDED
