using namespace std;

class Laptop : public Electronics
{
    public:
    int RAM, storage, gen, gCard;
    string processor;
    
    void SetData(string c,string m,int p, int y,int R,int stor,int g,string pro,int gCard=0)    // By default gCard will be 0
    {
        
        Electronics::SetData(c,m,p,y);
        RAM = R;
        storage = stor;
        gen = g;
        this->gCard = gCard;
        processor = pro;
    }

    void Display()
    {
        Electronics::Display();
        cout<<setw(2)<<RAM<<"GB   "<<setw(4)<<storage<<"GB    "<<setw(2)<<gCard<<"GB    "<<setw(10)<<processor<<"  "<<gen<<endl;
    }

    friend void SaveLaptop(vector<Laptop> &L);
    friend void RetrieveLaptop(vector<Laptop> &L);
};

void UpdateLaptop(vector<Laptop> &L)
{
    Laptop temp;

    temp.SetData("Dell","Inspiron15",70000, 2021,8,512,11,"i5",2);
    L.push_back(temp);

    temp.SetData("HP","Pavillion",48000, 2019,8,256,9,"i5");
    L.push_back(temp);

    temp.SetData("ASUS","HighPower",35000, 2019,8,256,8,"i3");
    L.push_back(temp);

    temp.SetData("ASUS","Rog",76000, 2021,8,512,9,"i5",4);
    L.push_back(temp);

    temp.SetData("Apple","MacBookAir",86000, 2021,8,512,10,"M1");
    L.push_back(temp);

    temp.SetData("AlienWare","M15",212000, 2021,16,1024,11,"i7",6);
    L.push_back(temp);

    temp.SetData("Dell","Vostro",36000, 2019,4,128,8,"i3");
    L.push_back(temp);

    temp.SetData("Predator","Helios300",106000, 2020,16,1024,10,"i5",6);
    L.push_back(temp);

    temp.SetData("Acer","Aspire3",45000, 2020,8,256,10,"i5",2);
    L.push_back(temp);

    temp.SetData("Lenovo","V15",44000, 2020,8,512,9,"i5");
    L.push_back(temp);
    
    temp.SetData("Apple","MacBookPro",250000, 2021,16,1024,11,"i7");
    L.push_back(temp);
}

void DisplayLaptop(vector<Laptop> &L)
{
    cout<<"Displaying Laptops..."<<endl<<endl;

    cout<<left<<setw(10)<<"Company"<<"  "<<left<<setw(10)<<"Model no"<<"  "<<setw(6)<<"Price"<<"  "<<"Year_of_mfg"<<"  ";
    cout<<" "<<setw(4)<<"RAM"<<"   "<<"Storage"<<"   "<<"G Card"<<"  "<<"Processor"<<"   "<<"Gen"<<endl<<endl;

    for(int i=0;i<L.size();i++)
    {
        L[i].Display();
    }
}


void SaveLaptop(vector<Laptop> &L)
{
    //cout<<"Writing in Laptop file..."<<endl;
    fstream fout;
    fout.open("LaptopsInfo.txt",ios::out);

    if(!fout) // Error Handling
    {perror("Error: ");exit(4);}

    fout<< L.size() <<endl;

    for(int i=0;i<L.size();i++)
    {
        fout << L[i].company   << endl
             << L[i].model_no <<endl
             << L[i].price << " "
             << L[i].year_of_mfg << " "
             << L[i].RAM << " "
             << L[i].storage << " "
             << L[i].gen << " "
             << L[i].gCard << endl
             << L[i].processor << endl<<endl;

    }
    fout.close();
    //cout<<"Written Succesfully"<<endl;
}

void RetrieveLaptop(vector<Laptop> &L)
{
    //cout<<"Retrieving Laptops...."<<endl;
    int size;
    fstream fin;
    fin.open("LaptopsInfo.txt",ios::in);

    if(!fin) // Error Handling
    {perror("Error: ");exit(3);}

    fin>>size;
    
    Laptop temp;

    for(int i=0;i<size;i++)
    {
        fin >> temp.company
            >> temp.model_no
            >>temp.price
            >>temp.year_of_mfg
            >>temp.RAM
            >>temp.storage
            >>temp.gen
            >>temp.gCard
            >>temp.processor;

        L.push_back(temp);
    }

    fin.close();
    //cout<<"Retrieved Successfully"<<endl;
}


void BudgetifyLaptops(vector<Laptop> &L)
{
    int lower, upper;
    cout<< "Enter Lower Limit : ";
    cin>>lower;
    cout<< "Enter Upper Limit : ";
    cin>>upper;
    cout<<"\n\nBudgetifying between your range..."<<endl<<endl;

    cout<<left<<setw(10)<<"Company"<<"  "<<left<<setw(10)<<"Model no"<<"  "<<setw(6)<<"Price"<<"  "<<"Year_of_mfg"<<"  ";
    cout<<" "<<setw(4)<<"RAM"<<"   "<<"Storage"<<"   "<<"G Card"<<"  "<<"Processor"<<"   "<<"Gen"<<endl<<endl;

    for(int i=0;i<L.size();i++)
    {
        if(L[i].price>=lower && L[i].price<=upper)
            L[i].Display();
    }
}


