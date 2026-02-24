#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class loginpage
{
private:
    string username;
    string password;
    string email;
public:
  void singin()
  {
    cout<<"enter your username:";
    getline(cin,username);
    cout<<endl;
    cout<<"\nenter your email:";
    getline(cin,email);
     cout<<endl;
    cout<<"\nenter your passward:";
    getline(cin,password);
      if( password.length()< 8 )

    {
        cout<<"your passward must have at least 8 digit";
        exit(0);
    }
     cout<<endl;
    ofstream file;
    file.open("data.txt",ios::app);
    if(file.is_open())
    {
    file<<username<<" "<<email<<" "<<password<<"\n";
    file.close();
    cout<<"you singup \n";
    }

    else
    {
        cout<<"error try again \n";
    }

  }
  void login ()
  {
    cout<<"for login pls enter your following detalis \n";
    string user,pass,em;
    bool found =false;
    cout<<"Enter your username:";
    getline(cin,user);
    cout<<"Enter your passward ";
    getline(cin,pass);
    cout<<"Enter your email";
    getline(cin,em);
    ifstream file("data.txt");


    if(file.is_open())
    {
        string u,p,e;

      while(file>>u>>e>>p)
      {

        if(u==user && p==pass && e==em)
        {
           found=true;
        }
        

    }
    file.close();
    if(found)
    {
        cout<<"\nlogin succses full";
    }
    else
    {
        cout<<"not found\n";
    }


    }
    
    else
    {
        cout<<"here is some trouble \n";
        cout<<"come after some time ";
    }
  }
};

int main()
{
    loginpage user1;
    
    int choice;
    cout<<" Enter your choice \n";
    cout<<"for signin press 1\n";
    cout<<"For login press 2 \n";
    cout<<"For exit press 3\n";

    cin>>choice;
     cin.ignore(); 

    if(choice==1)
    {
        user1.singin();
    }
    else if(choice==2)

    {
        user1.login();
    }
    else
    {
        cout<<"program exit succes full";
    }

}