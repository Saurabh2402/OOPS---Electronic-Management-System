
using namespace std;
class Fridge : public Electronics
{
public:

    int stars, doors, capacity, compressorWarranty;

    void SetData(string c,string m,int p, int y,int stars,int d, int capa, int warr)
    {
        if(p<0){
            cout<<"Invalid Price!!"<<endl;
            cout<<"Enter Price again : ";
            cin>>p;
        }
        Electronics::SetData(c,m,p,y);
        this->stars = stars;
        doors = d;
        capacity = capa;
        compressorWarranty = warr;
    }

    void Display()
    {
        Electronics::Display();
        cout<<"  "<<setw(5)<<stars<<"  "<<setw(5)<<doors<<"  "<<setw(4)<<capacity<<"L     "<<compressorWarranty<<" yrs"<<endl;
       // cout<<setw(5)<<stars<<"  "<<setw(5)<<doors<<"  "<<setw(8)<<capacity<<"  "<<compressorWarranty<<endl;
    }
};

void DisplayFridge(vector<Fridge> &F)
{
    cout<<"Displaying Fridges...."<<endl<<endl;
    cout<<left<<setw(10)<<"Company"<<"  "<<left<<setw(10)<<"Model no"<<"  "<<setw(5)<<"Price"<<"  "<<"Year_of_mfg"<<"  ";
    cout<<"Stars"<<"  "<<"Doors"<<"  "<<"Capacity"<<"  "<<"CompressorWarranty"<<endl<<endl;
    
    for(int i=0;i<F.size();i++)
    {
        F[i].Display();
    }
}

void UpdateFridge(vector<Fridge> &F)
{
    Fridge temp;
    temp.SetData("LG","Model3", 14000,2019,4,2,260,2);
    F.push_back(temp);

    temp.SetData("Whirlpool","Model6", 24000,2021,5,2,290,4);
    F.push_back(temp);

    temp.SetData("Samsung","Model5", 16000,2019,3,2,230,3);
    F.push_back(temp);

    temp.SetData("Godrej","Model2", 11000,2019,4,1,200,2);
    F.push_back(temp);

}

void SaveFridge(vector<Fridge> &F)
{
    //cout<<"Saving Fridges...";
    fstream fout;
    fout.open("FridgesInfo.txt",ios::out);

    if(!fout) // Error Handling
    {perror("Error: ");exit(5);}

    fout << F.size()<<endl;

    for(int i=0;i<F.size();i++)
    {
        fout<< F[i].company<<endl
            << F[i].model_no<<endl
            << F[i].price << " "
            << F[i].year_of_mfg << " "
            << F[i].stars << " "
            << F[i].doors << " "
            << F[i].capacity << " "
            << F[i].compressorWarranty << endl<<endl;
    }

    fout.close();
    //cout<<"Saved Succesfully..."<<endl;
}

void RetrieveFridge(vector<Fridge> &F)
{
    //cout<<"Retrieving Fridges...."<<endl;
    int size;
    fstream fin;
    fin.open("FridgesInfo.txt",ios::in);

    if(!fin) // Error Handling
    {perror("Error: ");exit(6);}

    fin>>size;
    Fridge temp;

    for(int i=0;i<size;i++)
    {   
        fin >>temp.company
            >>temp.model_no
            >>temp.price
            >>temp.year_of_mfg
            >>temp.stars
            >>temp.doors
            >>temp.capacity
            >>temp.compressorWarranty;

        F.push_back(temp);
    }
    fin.close();
    //cout<<"Retrieved Successfully"<<endl;
}

void BudgetifyFridges(vector<Fridge>&F)
{
    int lower, upper;
    cout<< "Enter Lower Limit : ";
    cin>>lower;
    cout<< "Enter Upper Limit : ";
    cin>>upper;
    cout<<"\n\nBudgetifying between your range..."<<endl<<endl;

    cout<<left<<setw(10)<<"Company"<<"  "<<left<<setw(10)<<"Model no"<<"  "<<setw(5)<<"Price"<<"  "<<"Year_of_mfg"<<"  ";
    cout<<"Stars"<<"  "<<"Doors"<<"  "<<"Capacity"<<"  "<<"CompressorWarranty"<<endl<<endl;
    for(int i=0;i<F.size();i++)
    {
        if(F[i].price>=lower && F[i].price<=upper)
            F[i].Display();
    }
}

void summaryFridge(vector<Fridge> &F)
{
    //cout<<"summaryFridge Function Called************"<<endl;

    int c_LG=0, c_whirlpool=0, c_samsung=0, c_godrej=0;
    for(int i=0;i<F.size();i++)
    {
        if(F[i].company=="LG")
            c_LG++;
        else if(F[i].company=="Whirlpool")
            c_whirlpool++;
        else if(F[i].company=="Samsung")
            c_samsung++;
        else if(F[i].company=="Godrej")
            c_godrej++;
        
    }
    cout << "Total Count of Fridges : "<<F.size()<<endl<<endl;
    cout << "LG        : " << c_LG         << endl;
    cout << "Whirlpool : " << c_whirlpool  << endl;
    cout << "Samsung   : " << c_samsung    << endl;
    cout << "Godrej    : " << c_godrej     << endl;
    cout<<endl<<endl;
    
}






