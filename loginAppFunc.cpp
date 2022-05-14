#include "loginAppFunc.h"


#define FILE_PATH "login.text"


void loodExsitingUsers(vector<string>& NA,vector<string>& ID,vector<string>& PASS,vector<string>& GM,vector<string>& NO)
{
    string name,id, pass, gmail, number;
    string word;
    int i = 0;

    fstream data_file;


    data_file.open(FILE_PATH,ios::in);

    if(data_file.is_open())
    {

        string line;
        getline(data_file, line);

        while (!data_file.eof()) //while the end of file is NOT reached
            {
                getline(data_file,name,'|');
                NA.push_back(name);
                getline(data_file,id,'|');
                ID.push_back(id);
                getline(data_file,pass,'|');
                PASS.push_back(pass);
                getline(data_file,gmail,'|');
                GM.push_back(gmail);
                getline(data_file,number,'|');
                NO.push_back(number);
                i += 1;
            }
            data_file.close();
    }
    else
    {
        cout << "\nFaild Open The File...\n";
        exit(0);
    }
}

void saveToFile(string data)
{
    ofstream login;
    login.open(FILE_PATH, ios::app);
    login << data;
    login.close();
}

char displayMenu()
{
    char option;
    cout << "\nPlease select what you want to do:  " << endl;
    cout << "1- New User" << endl;
    cout << "2- Login" << endl;
    cout << "3- Change Password" << endl;
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

void getPassword_l(string& password)
{
    password = hidePassword(password);
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
    const regex pattern("([A-Z]+[a-z]+[\\d]+[@$!%*#?&]*)|([A-Z]+[a-z]+[@$!%*#?&]+[\\d]*)|([A-Z]*[a-z]+[\\d]+[@$!%*#?&]+)|([A-Z]+[a-z]*[\\d]+[@$!%*#?&]+)|([A-Z]+[a-z]+[\\d]+[@$!%*#?&]+)[A-Za-z\\d@$!%*#?&]");
    // const regex pattern("(?=.*[A-Z])(?=.*[\\d@$!%*#?&])(?=.*[A-Z\\d@$!%*#?&])[A-Za-z\\d@$!%*#?&]{8,}");

/*
([a-z]+[\\d]+[A-Z]+[@$!%*#?&]*)|([a-z]+[\\d]+[@$!%*#?&]+[A-Z]*)|([a-z]+[A-Z]+[\\d]+[@$!%*#?&]*)|([A-Z]+[a-z]+[\\d]+[@$!%*#?&]*)|([A-Z]+[a-z]+[\\d]+[@$!%*#?&]*)|([A-Z]+[a-z]+[\\d]+[@$!%*#?&]*)|([\\d]+[A-Z]+[a-z]+[@$!%*#?&]*)|([\\d]+[a-z]+[A-Z]+[@$!%*#?&]*)|([\\d]+[@$!%*#?&]+[A-Z]+[a-z]*)|([@$!%*#?&]+[A-Z]+[a-z]+[\\d]*)|([@$!%*#?&]+[a-z]+[A-Z]+[\\d]*)|([@$!%*#?&]+[a-z]+[\\d]+[A-Z]*)|


([A-Z]+[a-z]+[\\d]+[@$!%*#?&]*)|
([A-Z]+[a-z]+[\\d]+[@$!%*#?&]*)|
([A-Z]+[a-z]+[\\d]+[@$!%*#?&]*)|
([A-Z]+[a-z]+[\\d]+[@$!%*#?&]*)|
([A-Z]+[a-z]+[\\d]+[@$!%*#?&]*)|
([A-Z]+[a-z]+[\\d]+[@$!%*#?&]*)|
([A-Z]+[a-z]+[\\d]+[@$!%*#?&]*)|
([A-Z]+[a-z]+[\\d]+[@$!%*#?&]*)|
([A-Z]+[a-z]+[\\d]+[@$!%*#?&]*)|
([A-Z]+[a-z]+[\\d]+[@$!%*#?&]*)|
([A-Z]+[a-z]+[\\d]+[@$!%*#?&]*)|
([A-Z]+[a-z]+[\\d]+[@$!%*#?&]*)|



*/


    while(!regex_match(password,pattern))
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

bool ID_check(string ID)
{
    const regex pattern("20[0-2][0-9][0-9]{4}");
    return regex_match(ID,pattern);
}

void validateUsername(vector<string>& NA, string& username)
{
    int size = NA.size();
    for(int i = 0 ; i <= size - 1; i++  )
        {
            while (true)
            {
                if(NA[i] == username)
                {
                    cout <<"This Username already exists, try another one!";
                    getline(cin,username);
                }else
                {
                    break;
                }
            }
        }
}

void validateID(vector<string>& ID, string& I_D )
{
    int size = ID.size();
    for(int i = 0 ; i <= size - 1; i++  )
        {
            while (true)
            {
                if(ID[i] == I_D)
                {
                    cout <<"This ID already exists, try another one!";
                    getline(cin,I_D);
                }else
                {
                    break;
                }
            }
        }
}

void validateEmail(vector<string>& GM, string& email )
{
    int size = GM.size();
    for(int i = 0 ; i <= size - 1; i++  )
        {
            while (true)
            {
                if(GM[i] == email)
                {
                    cout <<"This email already exists, try another one!";
                    getline(cin,email);
                }else
                {
                    break;
                }
            }
        }
}


void newuser()
{
    //saveToFile("\n");
    string x = "User name";
    string username;
    string I_D;
    string password = " ";
    string password2 = " ";
    string email = " ";
    char phone[11];

    while(x == "User name")
    {
        cin.ignore();
        cout <<"create a username: ";
        getline(cin, username);
        validateUsername(NA, username);
        if(username_check(username))
        {
            cout <<"username created successfully"<<endl;
            saveToFile("\n");
            saveToFile(username);
            saveToFile("|");
            x = "ID";
        }else
        {
            cout<<"invalid username! press enter, please "<<endl;
        }
    }


    while (x=="ID"){
        cout<<"enter your ID: ";
        cin>> I_D;
        validateID(ID, I_D );
        if (ID_check(I_D))
        {
            cout<<"ID is correct "<<endl;
            saveToFile(I_D);
            saveToFile("|");
            x="Password";
        }
        else
            cout<<"wrong ID "<<endl;
    }

    while (x == "Password")
    {
        getPassword(password);
        strong_password_check(password);
        repeatPassword(password, password2);

        x = "Email";
    }

    saveToFile(railFence(password,3,"encrypt"));
    saveToFile("|");

    while (x == "Email")
    {
        cout<<"create an email: ";
        cin >> email;
        validateEmail(GM, email);
        if(Email_check(email))
        {
            cout <<"email created successfully"<<endl;
            saveToFile(email);
            saveToFile("|");
            x = "Phone";
        }
        else
        {
            cout<<" invalid email"<<endl;
        }
    }
    while (x == "Phone"){
        cout <<"enter your phone number: ";
        cin>>phone;

        if(phone_check(phone))
        {
            cout << "right phone number \n";
            saveToFile(phone);
            saveToFile("|");
            break;
        }
        else
        {
            cout<<"invalid phone number"<<endl;
        }
    }
    exit(0);
}


static std::string removeSpaces(std::string str)
{
	str.erase(remove(str.begin(), str.end(), '\n'), str.end());
	return str;
}

void login(vector<string>n_a,vector<string>i_d,vector<string>p_s,int len,int count){
    string PASSWORD, I_D;
    int n =0;
    cout << "\nEnter Your Id: ";
    cin >> I_D;
    cout << "Enter Your Password: " ;
    getPassword_l(PASSWORD);

    if (CHECK_USRER_AND_PASS(I_D,PASSWORD,n_a,i_d,p_s,len)){
        n = CHECK_USRER_AND_PASS(I_D,PASSWORD,n_a,i_d,p_s,len)-1;
        cout << "Successful login, welcome "<<removeSpaces(n_a[n])<<endl;
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


void change_pass(vector<string>n_m,vector<string>i_d,vector<string>p_s,vector<string>g_m,vector<string>n_o){
    string id,pass = " ",new_pass;
    cout << "Enter Your Id: ";
    cin >> id;
    cout << "Enter Old Password: ";
    getPassword_l(pass);
    int size =i_d.size();
    for (int i =0 ; i < size-1; i++){
        if (i_d[i] == id && railFence(p_s[i],3,"decript") == pass ){
            cout << "Enter New Password => ";
            cin.ignore();
            getPassword(p_s[i]);
            strong_password_check(p_s[i]);            //When change
            string password2 = " ";
            repeatPassword(p_s[i], password2);
            save_new_pass(n_m,i_d,p_s,g_m,n_o);
        }
    }
    cout << "Wrong Password!..."<< endl << "---------------------------\n";
}


void save_new_pass(vector<string>n_m,vector<string>i_d,vector<string>p_s,vector<string>g_m,vector<string>n_o){
    ofstream save_file;
    save_file.open(FILE_PATH, ios::out);
    save_file << "Name" << '|'<< "ID" << '|'<< "PASSWORD" << '|'<< "Gmail" << '|' << "Number" << '\n';
    int size =i_d.size();
    for (int i =0 ; i < size-1; i++){ // -------------------------------------------> for (int i =0 ; i < len_c; i++) ----NOT WORK
        save_file << n_m[i] << '|'<< i_d[i] << '|'<< p_s[i] << '|'<< g_m[i] << '|' << n_o[i] << '|';
    }
    save_file.close();
    cout << "Your Password Changed!...\n\n";
    cout <<"Thanks for using our App. \n";
    exit(0);
}


int CHECK_USRER_AND_PASS(string id ,string pass,vector<string>n_a,vector<string>i_d,vector<string>p_s,int len_c){
    int h = 0, size =i_d.size();
    for (int i =0 ; i < size; i++){ // -------------------------------------------> for (int i =0 ; i < len_c; i++) ----NOT WORK
        if (i_d[i] == id && railFence(p_s[i],3,"decript") == pass ){
            h=i+1;
        }
    }
    return h;
}

string encript(string& password){
    int size = password.length();
    char enc_pass[size];
    for (int i =0 ; i< password.length();i++){
        enc_pass[i] =  (password[i] - 3);
    }
    return enc_pass;
}


string decript(string& password){
    int size = password.length();
    char dec_pass[size];
    for (int i =0 ; i< password.length();i++){
        dec_pass[i] =  (password[i] + 3);
    }
    return dec_pass;
}


string railFence(string text, int base, string answer)
{
    vector<vector<string>> vectors{};
    vector<string> tempVector{};
    string dash{""};
    int textLength = text.length();
    for (int i = 0; i < textLength; i++)
    {
        tempVector.push_back(dash);
    }
    for (int i = 0; i < base; i++)
    {
        vectors.push_back(tempVector);
    }

    int counter{0};
    int neg{1};
    string value;
    if (answer == "encrypt")
    {
        for (int i = 0; i < textLength; i++)
        {
            vectors[counter][i] = text[i];
            counter += 1 * neg;
            neg = (counter == base - 1 || !counter) ? neg * -1 : neg;
        }
        int textIndex = 0;
        for (int i = 0; i < vectors.size(); i++)
        {
            for (int j = 0; j < vectors[i].size(); j++)
            {
                if (vectors[i][j] != dash)
                {
                    value += vectors[i][j];
                    textIndex += 1;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < textLength; i++)
        {
            vectors[counter][i] = text[i];
            counter += 1 * neg;
            neg = (counter == base - 1 || !counter) ? neg * -1 : neg;
        }
        int textIndex = 0;
        for (int i = 0; i < vectors.size(); i++)
        {
            for (int j = 0; j < vectors[i].size(); j++)
            {
                if (vectors[i][j] != dash)
                {
                    vectors[i][j] = text[textIndex];
                    textIndex += 1;
                }
            }
        }
        counter = 0;
        neg = 1;
        for (int i = 0; i < textLength; i++)
        {
            value += vectors[counter][i];
            counter += 1 * neg;
            neg = (counter == base - 1 || !counter) ? neg * -1 : neg;
        }
    }
    return value;
}