/*#include <iostream>
#include<vector>
#include<fstream>
#include<iomanip>*/
using namespace std;
class User
{
    string username, password;

public:
    User()
    {
        username = "";
        password = "";
    }
    User(string uname, string pass)
    {
        this->username = uname;
        this->password = pass;
    }
    friend class Authentication;
};

class Authentication
{
    vector<User> Users;
public:
    Authentication()
    {Retrieve();}
    Authentication(int a)
    {}

    bool logIn()
    {
        cout << "Login with your credentials"<<endl;
        string uname, pass;
        
        cin.clear();
        cout << "\nEnter username: ";
        cin>>uname;
        cout << "Enter password: ";
        cin>>pass;

        for(int i=0;i<Users.size();i++)
        {
            if(Users[i].username == uname && Users[i].password==pass)
            {
                cout<<"Login Successfull!"<<endl;
                return true;
            }
        }
        cout << "\n\tLogin Unsucessfull!! Try again!";
        return false;
    }

    void signUp()
    {
        string uname, pass,buff;
        User usr;
        
        cout << "\nEnter username for registration: ";
        cin>>usr.username;
        cout << "Enter password for registration: ";
        cin>>usr.password;
        Users.push_back(usr);

        Save();
        cout << "Registration done"<<endl<<endl;
    }
 
    void DisplayUsers()
    {
        //cout<<"Displaying Users..."<<endl<<endl;
        cout<<setw(15)<<"Usernames"<<setw(15)<<"Passwords"<<endl<<endl;
        for(int i=0;i<Users.size();i++)
        {
            cout<<setw(15)<<Users[i].username<<setw(15)<<Users[i].password<<endl;
        }
        cout<<endl;
    }

    void Save()
    {
       // cout<<"Saving..."<<endl;
        ofstream fout;
        fout.open("UsersInfo.txt");
        if(!fout)
        {
            perror("Error: ");exit(7);
        }
        fout<<Users.size()<<endl;

        for(int i=0;i<Users.size();i++)
        {
            fout << Users[i].username<<endl
                 << Users[i].password<<endl<<endl;
        }

        fout.close();
        //cout<<"Saved Succesfully..."<<endl;
    }
  
    void Retrieve()
    {
       // cout<<"Retrieving Info..."<<endl;
        User usr;
        int size;
        ifstream fin;
        fin.open("UsersInfo.txt");
        if(!fin)
        {
            perror("Error: ");exit(7);
        }
        fin >> size;
        for(int i=0;i<size;i++)
        {
            fin >> usr.username >> usr.password;
            Users.push_back(usr);
        }
        fin.close();
        //cout<<"Retrieved Successfully..."<<endl;
    }

    int Menu()
    {
        cout<<"1 : SignUp"<<endl;
        cout<<"2 : LogIn"<<endl;
        cout<<"3 : Display usernames and passwords"<<endl;
        cout<<"4 : Exit"<<endl;
        cout<<"Enter your choice : ";
        int choice;
        cin>>choice;
        cout<<endl;
        return choice;
    }
};

void MainAuthentication()
{
    cout<<"Authenticating...."<<endl<<endl;
    
    Authentication Auth;
    
    
    char choice='y';
    bool hasLoggedIn = false;
    while(choice!='n')
    {
        int answer = Auth.Menu();
        switch(answer)
        {
            case 1: Auth.signUp();break;
            case 2: {
                        bool temp = false;
                        while (!temp)
                        {
                            temp = Auth.logIn();
                            hasLoggedIn = temp;
                        }
                        break;
                    }
            case 3: Auth.DisplayUsers();break;
            case 4: exit(8);
            default: cout<<"Invalid Choice!!"<<endl;

        }
        if(!hasLoggedIn)
        {
            cout<<"Do you want to continue(y/n) : ";
            cin>>choice;
            cout<<endl;
        }
        if(hasLoggedIn)
            return;
    }
    

}