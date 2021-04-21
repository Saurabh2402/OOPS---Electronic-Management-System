#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include"class_Electronics.h"
#include"class_Mobile.h"
#include"SortFunctions.h"


using namespace std;

void Update(vector<Mobile> &M)
{
    Mobile temp;

    temp.SetData("Samsung","GalaxyM31",22000,2021,64,6,128,"SnapDragon");
    M.push_back(temp);

    temp.SetData("Iphone","12Pro",50000,2020,64,8,128,"AppleM3");
    M.push_back(temp);

    temp.SetData("Nokia","Note5",17000,2021,32,4,64,"SnapDragon");
    M.push_back(temp);

    temp.SetData("RedMI","Note7Pro",20000,2020,64,4,64,"SnapDragon");
    M.push_back(temp);

    temp.SetData("MicroMax","10i",12000,2021,32,4,64,"SnapDragon");
    M.push_back(temp);

    temp.SetData("Iphone","5s",20000,2017,16,4,32,"AppleM");
    M.push_back(temp);

    temp.SetData("OnePlus","9t",36000,2021,64,8,128,"SnapDragon");
    M.push_back(temp);
}

void Display(vector<Mobile> &M)
{
    cout<<"Displaying Mobiles\n\n";
    cout<<left<<setw(10)<<"Company"<<"  "<<left<<setw(10)<<"Model no"<<"  "<<setw(5)<<"Price"<<"  "<<"Year_of_mfg"<<"  ";
    cout<<setw(4)<<"RAM"<<"   "<<"Storage"<<"  "<<"Camera"<<"  "<<"Processor"<<endl;
    for(int i=0;i<M.size();i++)
            M[i].Display();
}

void SaveToFiles(vector<Mobile>&M)
{
    cout<<"Writing in a file...."<<endl;

    fstream fout;
    fout.open("MobilesInfo.txt",ios::out);
  
    fout<< M.size()<<endl;
    for(int i=0;i<M.size();i++)
    {
        fout<<  M[i].company      << endl
            <<  M[i].model_no     << endl
            <<  M[i].price        << " "
            <<  M[i].year_of_mfg  << " "
            <<  M[i].camera       << " "
            <<  M[i].RAM          << " "
            <<  M[i].storage      << endl
            <<  M[i].processor    << endl << endl;

    }
    fout.close();
    cout<<"Written Succesfully"<<endl;
}

void RetrieveFiles(vector<Mobile>&M)
{
    cout<<"Retrieving Databases...."<<endl;
    int size;
    fstream fin;
    fin.open("MobilesInfo.txt",ios::in);
    fin>>size;
    string buff;
    Mobile temp;

    for(int i=0;i<size;i++)
    {
        
       
       fin>> temp.company
          >> temp.model_no
          >> temp.price
          >> temp.year_of_mfg
          >> temp.RAM
          >> temp.camera
          >> temp.storage
          >> temp.processor;

        M.push_back(temp);
        
    }
    fin.close();
    cout<<"Retrieved Successfully"<<endl;
}

void Budgetify(vector<Mobile> M,int lower,int upper)
{
    cout<<"\n\nBudgetifying between your range..."<<endl<<endl;
    for(int i=0;i<M.size();i++)
    {
        if(M[i].price>=lower && M[i].price<=upper)
            M[i].Display();
    }
}

int main()
{
    cout<<"\t\t\t"<<"Welcome to Eletronics Management System!!"<<endl<<endl;
    vector<Mobile> MobileVector;
    /*
    Update(MobileVector);
    Display(MobileVector);
    SaveToFiles(MobileVector);
    */
    
    //Display(MobileVector);
    RetrieveFiles(MobileVector);
    Display(MobileVector);
    
   // Budgetify(MobileVector,15000,40000);

   //Sort_by_Price(MobileVector); --Working fine
   //Sort_by_Camera(MobileVector); -- All Sorts working
   Display(MobileVector);
}