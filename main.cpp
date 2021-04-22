#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include"class_Electronics.h"
#include"class_Mobile.h"
#include"class_Laptops.h"
#include"class_Fridge.h"
#include"SortFunctions.h"

using namespace std;

int Menu();
void Update(vector<Mobile>&M, vector<Laptop>&L,vector<Fridge>&F);
void Save(vector<Mobile>&M, vector<Laptop>&L,vector<Fridge>&F);
void Retrieve(vector<Mobile>&M, vector<Laptop>&L,vector<Fridge>&F);
void Display(vector<Mobile>&M, vector<Laptop>&L,vector<Fridge>&F);
void Budgetify(vector<Mobile>&M, vector<Laptop>&L,vector<Fridge>&F);

int main()
{
    system("cls");
    cout<<"\n\t\t"<<"Welcome to Eletronics Management System!!"<<endl;
    vector<Mobile> MobileVector;
    vector<Laptop> LaptopVector;
    vector<Fridge> FridgeVector;
   char choice = 'y';
    while(choice=='y' || choice=='Y')
    {
        int answer;
        answer = Menu();

        switch(answer)
        {
            case 1: Update(MobileVector,LaptopVector,FridgeVector); break;
            case 2: Budgetify(MobileVector,LaptopVector,FridgeVector); break;
            case 3: Save(MobileVector,LaptopVector,FridgeVector); break;
            case 4: Retrieve(MobileVector,LaptopVector,FridgeVector); break;
            case 5: Display(MobileVector,LaptopVector,FridgeVector); break;
            case 6: Sort(MobileVector,LaptopVector,FridgeVector);break;
            case 0: cout<<"Program Closed!!";exit(1);

            default : cout<<"Invalid Input!!"<<endl;
            
        }
        cout<<"\nDo you want to continue with the system (y/n) ? : ";
        cin>>choice;
        cout<<endl;
        if(choice!='n')
            choice = 'y';
    }
    cout<<"Program Closed by your choice!!"<<endl<<endl;
    
/*
    Retrieve(MobileVector,LaptopVector);
    Display(MobileVector,LaptopVector);
    Sort_by_Storage<Mobile>(MobileVector);
    Display(MobileVector,LaptopVector);
*/
    
    
}


int Menu()
{
    //system("cls");
    cout<<right<<setw(15)<<"MENU" <<endl<<endl;
    cout<<"1: Update Electronics"       <<endl;
    cout<<"2: Budgetify" <<endl;
    cout<<"3: Save Files"               <<endl;
    cout<<"4: Retrieve Files"           <<endl;
    cout<<"5: Display Electronics"      <<endl;
    cout<<"6: Sort Electronics"         <<endl;
    cout<<"0: Exit System"              <<endl;

    cout<<">> Enter Your choice : ";
    int answer;
    cin>>answer;
    cout<<endl;
    return answer;
}

void Update(vector<Mobile>&M, vector<Laptop>&L, vector<Fridge>&F)
{
    cout<<"1: Update Mobiles"<<endl;
    cout<<"2: Update Laptops"<<endl;
    cout<<"3: Update Fridges"<<endl;
    int choice;
    cout<<"Enter your choice : ";
    cin>>choice;
    cout<<endl;

    switch(choice)
    {
        case 1: UpdateMobile(M);break;
        case 2: UpdateLaptop(L);break;
        case 3: UpdateFridge(F);break;
        default : cout<<"Invalid Choice!!"<<endl;
    }
}

void Save(vector<Mobile>&M, vector<Laptop>&L,vector<Fridge>&F)
{
    SaveMobiles(M);
    SaveLaptop(L);
    SaveFridge(F);
    cout<<"Saved Succesfully..."<<endl;
}

void Retrieve(vector<Mobile>&M, vector<Laptop>&L,vector<Fridge>&F)
{
    RetrieveMobiles(M);
    RetrieveLaptop(L);
    RetrieveFridge(F);
    cout<<"Retrieved Succesfully..."<<endl;
}

void Display(vector<Mobile>&M, vector<Laptop>&L,vector<Fridge>&F)
{
    cout<<"1: Display Mobiles"<<endl;
    cout<<"2: Display Laptops"<<endl;
    cout<<"3: Display Fridges"<<endl;
    int choice;
    cout<<"Enter your choice : ";
    cin>>choice;
    cout<<endl;

    switch(choice)
    {
        case 1: DisplayMobile(M);break;
        case 2: DisplayLaptop(L); break;
        case 3: DisplayFridge(F);break;
        default: cout<<"Invalid Input!!"<<endl;
    }
}

void Budgetify(vector<Mobile>&M, vector<Laptop>&L,vector<Fridge>&F)
{
    cout<<"1: Budgetify Mobiles"<<endl;
    cout<<"2: Budgetify Laptops"<<endl;
    cout<<"3: Budgetify Fridges"<<endl;
    int choice;
    cout<<"Enter your choice : ";
    cin>>choice;
    cout<<endl;

    switch(choice)
    {
        case 1: BudgetifyMobiles(M);break;
        case 2: BudgetifyLaptops(L);break;
        case 3: BudgetifyFridges(F);break;
        default : cout<<"Invalid Choice!!"<<endl;
    }
}
