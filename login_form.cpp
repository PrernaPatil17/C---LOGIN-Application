#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main(){
 
    int choice;
    cout<<"\t\t\t__________________________________________________\n\n\n";
    cout<<"\t\t\t              WELCOME TO LOGIN PAGE                \n\n\n";
    cout<<"\t\t\t________________________MENU______________________\n\n\n";
    cout<<"press 1 to login"<<endl;
    cout<<"press 2 to register"<<endl;
    cout<<"press 3 if you forgot your password"<<endl;
    cout<<"press 4 to EXIT"<<endl;
    cout<<"please enter your choice: ";
    cin>>choice;
    cout<<endl;

    switch(choice){
        case 1:
         login();
         break;

        case 2:
         registration();
         break;
        
        case 3:
         forgot();
         break;

        case 4:
         cout<<"Thank you";
         break;

        default:
         cout<<"invalid choice.please enter an valid choice";
    }

    return 0;
}

void login(){
    int count;
    string userid,
           password,
           id,
           pass;

    cout<<"please enter the username and password: "<<endl;
    cout<<"username: "<<endl;
    cin>>userid;
    cout<<"password: "<<endl;
    cin>>password;

    ifstream input("record.txt"); //ifstream if you wnat to read or check from the file

    while(input>>id>>pass){
        if(id==userid && pass==password){
            count=1;
            system("cls");
        }
    }
    input.close();

    if (count==1)
    {
       cout<<userid<<"your login is successfull!!!!!!!"<<endl;
       main();
    }
    else{
        cout<<"login error: please check your username and password"<<endl;
        main();
    }
}

void registration(){
    string reg_userid,
           reg_password,
           r_id,
           r_pass;

    cout<<"enter the username you want to register ";
    cin>>reg_userid;
    cout<<endl;
    cout<<"enter the password you want to register ";
    cin>>reg_password;
    cout<<endl;

    ofstream f1("record.txt",ios::app);
    f1<<reg_userid<<' '<<reg_password<<endl;
    cout<<"registration is successfull";
    main();

}

void forgot(){
    int option;
    system("cls");
    cout<<"forgot password?"<<endl;
    cout<<"press 1 to search your id by username "<<endl;
    cout<<"press 2 to go back to the main menu "<<endl;
    cout<<"enter your option: "<<endl;
    cin>>option;
    switch(option)
    {
    case 1:{
        int count=0;
        string suserid,sid,spass;
        cout<<"enter the username which you remember"<<endl;
        cin>>suserid;
        
        ifstream f2("record.txt");
        while (f2>>sid>>spass)
        {
            if (sid==suserid)
            {
                count=1;
            }
            f2.close();

            if(count==1){
                cout<<"your account is found!"<<endl;
                cout<<"your password is: "<<spass;
                main();
            }
            else{
                cout<<"sorry your account is not found!"<<endl;
                main();
            }
        }
    }
            break;
        case 2:
         {
            main();
         }
         break;
         
         default:
          cout<<"wrong option please enter an valid option"<<endl;
          forgot();
          break;
    }
    
}
