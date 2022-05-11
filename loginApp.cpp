#include "loginApp.h"

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
    cout << "2- Login" << endl;
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


void newuser()
{

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

void login(vector<string>n_a,vector<string>i_d,vector<string>p_s,int len,int count){
    string PASSWORD, I_D;
    int n =0;
    cout << "\nEnter Your Id: ";
    cin >> I_D;
    cout << "Enter Your Password: " ;
    
    cin >> PASSWORD;

    if (CHECK_USRER_AND_PASS(I_D,PASSWORD,n_a,i_d,p_s,len)){
        int n = CHECK_USRER_AND_PASS(I_D,PASSWORD,n_a,i_d,p_s,len)-1;
        cout << n;
        cout << "Successful login, welcome "<<n_a[n];
    }
    else {
        cout << "Failed login. Try again.";
        count ++ ;

        if (count == 3){
            cout << "\nYou are denied access to the system....";
            exit(0);
            // Here Put function main menu                              <--------------------------------------------------
        }
        login(n_a,i_d,p_s,len,count);
    }
}

int CHECK_USRER_AND_PASS(string id ,string pass,vector<string>n_a,vector<string>i_d,vector<string>p_s,int len_c){
    int h = 0, size =i_d.size();
    for (int i =0 ; i < size-1; i++){ // -------------------------------------------> for (int i =0 ; i < len_c; i++) ----NOT WORK
        if (i_d[i] == id && p_s[i] == pass ){
            h=i+1;
        }
    }
    return h;
}