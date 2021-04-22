#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include"class_Electronics.h"
#include"class_Mobile.h"
#include"class_Laptops.h"
#include"SortFunctions.h"

using namespace std;

int Menu();
void Update(vector<Mobile>&M, vector<Laptop>&L);
void Save(vector<Mobile>&M, vector<Laptop>&L);
void Retrieve(vector<Mobile>&M, vector<Laptop>&L);
void Display(vector<Mobile>&M, vector<Laptop>&L);
void Budgetify(vector<Mobile>&M, vector<Laptop>&L);

int main()
{
    cout<<"\t\t\t"<<"Welcome to Eletronics Management System!!"<<endl<<endl;
    vector<Mobile> MobileVector;
    vector<Laptop> LaptopVector;

   char choice = 'y';
    while(choice=='y' || choice=='Y')
    {
        int answer;
        answer = Menu();

        switch(answer)
        {
            case 1: Update(MobileVector,LaptopVector); break;
            case 2: Budgetify(MobileVector,LaptopVector); break;
            case 3: Save(MobileVector,LaptopVector); break;
            case 4: Retrieve(MobileVector,LaptopVector); break;
            case 5: Display(MobileVector,LaptopVector); break;
            case 6: Sort(MobileVector,LaptopVector);break;
            case 0: cout<<"Program Closed!!";exit(1);

            default : cout<<"Invalid Input!!"<<endl;
            
        }
    }
/*
    Retrieve(MobileVector,LaptopVector);
    Display(MobileVector,LaptopVector);
    Sort_by_Storage<Mobile>(MobileVector);
    Display(MobileVector,LaptopVector);
*/
    
   

}


int Menu()
{
    cout<<endl<<right<<setw(15)<<"MENU" <<endl<<endl;
    cout<<"1: Update Electronics"       <<endl;
    cout<<"2: Budgetify" <<endl;
    cout<<"3: Save Files"               <<endl;
    cout<<"4: Retrieve Files"           <<endl;
    cout<<"5: Display Electronics"      <<endl;
    cout<<"6: Sort Electronics"         <<endl;
    cout<<"0: Exit System"              <<endl;

    cout<<"Enter Your choice : ";
    int answer;
    cin>>answer;
    cout<<endl;
    return answer;
}

void Update(vector<Mobile>&M, vector<Laptop>&L)
{
    cout<<"1: Update Mobiles"<<endl;
    cout<<"2: Update Laptops"<<endl;

    int choice;
    cout<<"Enter your choice : ";
    cin>>choice;
    cout<<endl;

    switch(choice)
    {
        case 1: UpdateMobile(M);break;
        case 2: UpdateLaptop(L);break;

        default : cout<<"Invalid Choice!!"<<endl;
    }
}

void Save(vector<Mobile>&M, vector<Laptop>&L)
{
    SaveMobiles(M);
    SaveLaptop(L);
}

void Retrieve(vector<Mobile>&M, vector<Laptop>&L)
{
    RetrieveMobiles(M);
    RetrieveLaptop(L);

}

void Display(vector<Mobile>&M, vector<Laptop>&L)
{
    cout<<"1: Display Mobiles"<<endl;
    cout<<"2: Display Laptops"<<endl;
    int choice;
    cout<<"Enter your choice : ";
    cin>>choice;
    cout<<endl;

    switch(choice)
    {
        case 1: DisplayMobile(M);break;
        case 2: DisplayLaptop(L); break;

        default: cout<<"Invalid Input!!"<<endl;
    }
}

void Budgetify(vector<Mobile>&M, vector<Laptop>&L)
{
    cout<<"1: Budgetify Mobiles"<<endl;
    cout<<"2: Budgetify Laptops"<<endl;

    int choice;
    cout<<"Enter your choice : ";
    cin>>choice;
    cout<<endl;

    switch(choice)
    {
        case 1: BudgetifyMobiles(M);break;
        case 2: BudgetifyLaptops(L);break;

        default : cout<<"Invalid Choice!!"<<endl;
    }
}
