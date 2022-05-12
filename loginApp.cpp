// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: login.cpp
// Last Modification Date: xx/xx/xxxx
// Author1 and ID and Group: Abdelrahman Tarek Mohamed   20210206
// Author2 and ID and Group: Adel Magdy Abd El-Hay       20210190
// Author3 and ID and Group: Roaa Talat Mohamed          20210138
// Teaching Assistant: Dr.Mohamed Al Ramly
// Purpose:..........@bd00Tarek4




#include "loginAppFunc.h"
#include "loginAppFunc.cpp"

#define FILE_PATH "login.txt"

int main()
{

    cout<<"Welcome to our login App.";
    char choice;
    while (true)
    {
        choice = displayMenu();
        if (choice == '1')
        {
            newuser();
        }
        else if(choice == '2'){

            //-------------------------NEED PUT IT IN FUNCTION-----------------------------
            string name,id, pass, gmail, number;
            string word;
            int i = 0;
            vector<string>NA;
            vector<string>ID;
            vector<string>PASS;
            vector<string>GM;
            vector<string>NO;

            fstream data_file;

            // cout << "Enter file Path (Ex: file.txt)\n>>> ";
            // cin >> FILE_PATH ;

            data_file.open(FILE_PATH,ios::in);

            if(data_file.is_open()){

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
            else cout << "Faild Open The File, Try again...\n";
        //---------------------------------------------------------------------

            int count = 0;    //      PUT   count = 0    IN  function main menu
            int size = 0;   //*(&users + 1) - users;
            login(NA,ID,PASS,size,count);

        }
        else if (choice == '3'){

            //-------------------------NEED PUT IT IN FUNCTION-----------------------------
            string name,id, pass, gmail, number;
            string word;
            int i = 0;
            vector<string>NA;
            vector<string>ID;
            vector<string>PASS;
            vector<string>GM;
            vector<string>NO;

            fstream data_file;

            // cout << "Enter file Path (Ex: file.txt)\n>>> ";
            // cin >> file_path ;

            data_file.open(FILE_PATH,ios::in);

            if(data_file.is_open()){

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
            else {
                cout << "Faild Open The File...\n";
                exit(0);
            }

        //---------------------------------------------------------------------

            change_pass(NA,ID,PASS,GM,NO);

            }

        else
        {
            cout << "Thanks for using our App. \n" << endl;
            return 0;
        }
     }
}
