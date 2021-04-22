
using namespace std;

class Mobile : public Electronics
{
    public:
    int camera, RAM, storage;
    string processor;

    void SetData(string c,string m,int p, int y,int cam,int R,int stor,string pro)
    {
        Electronics::SetData(c,m,p,y);
        camera = cam;
        RAM = R;
        storage = stor;
        processor = pro;
    }
    
    void Display()
    {
        Electronics::Display();
        cout<<setw(2)<<RAM<<"GB   "<<setw(3)<<storage<<"GB    "<<setw(2)<<camera<<"MP    "<<setw(10)<<processor<<endl;
    }

    
    friend void SaveMobiles(vector<Mobile> &M);
    friend void RetrieveMobiles(vector<Mobile> &M);
};

void UpdateMobile(vector<Mobile> &M)
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

void DisplayMobile(vector<Mobile> &M)
{
    cout<<"Displaying Mobiles....\n\n";
    cout<<left<<setw(10)<<"Company"<<"  "<<left<<setw(10)<<"Model no"<<"  "<<setw(5)<<"Price"<<"  "<<"Year_of_mfg"<<"  ";
    cout<<setw(4)<<"RAM"<<"   "<<"Storage"<<"  "<<"Camera"<<"  "<<"Processor"<<endl;
    for(int i=0;i<M.size();i++)
            M[i].Display();
}

void SaveMobiles(vector<Mobile>&M)
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

void RetrieveMobiles(vector<Mobile>&M)
{
    cout<<"Retrieving Mobiles ...."<<endl;
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

void BudgetifyMobiles(vector<Mobile> &M)
{
    int lower, upper;
    cout<< "Enter Lower Limit : ";
    cin>>lower;
    cout<< "Enter Upper Limit : ";
    cin>>upper;
    cout<<"\nBudgetifying between your range..."<<endl<<endl;

    cout<<left<<setw(10)<<"Company"<<"  "<<left<<setw(10)<<"Model no"<<"  "<<setw(5)<<"Price"<<"  "<<"Year_of_mfg"<<"  ";
    cout<<setw(4)<<"RAM"<<"   "<<"Storage"<<"  "<<"Camera"<<"  "<<"Processor"<<endl;
    for(int i=0;i<M.size();i++)
    {
        if(M[i].price>=lower && M[i].price<=upper)
            M[i].Display();
    }
}

