
using namespace std;

int getPositiveValue(int v,int index)
{
    try
    {
        if(v<0)
        {
            if(index==1)
                cout<<"Camera MegaPixels cannot be Negative!!"<<endl;
            else if(index==2)
                cout<<"RAM cannot be Negative!!"<<endl;
            else if(index==3)
                cout<<"Storage cannot be Negative!!"<<endl;
            else if(index==4)
                cout<<"Graphic Card cannot be Negative!!"<<endl;    
            
            throw(222);
            
        }
    }
    catch(int n)
    {
        if(n==222)
        {
            cout<<"Enter value again : ";
            cin>>v;
        }
        
    }
     
    return v;
}

class Mobile : public Electronics
{
    public:
    int camera, RAM, storage;
    string processor;

    void SetData(string c,string m,int p, int y,int cam,int R,int stor,string pro)
    {
        
        cam = getPositiveValue(cam,1);
        R = getPositiveValue(R,2);
        stor = getPositiveValue(stor,3);

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
    //Update many mobiles
    {
    /*Mobile temp;
                //Company, Modelno, Price, YearOfMfg, Camera, RAM, Storage, Processor
                                            // /->Year purposely set 2000 
    temp.SetData("Samsung","GalaxyM31",22000,2000,64,6,128,"SnapDragon");
    M.push_back(temp);

    temp.SetData("Iphone","12Pro",50000,2020,64,8,-128,"AppleM3");
    M.push_back(temp);

    temp.SetData("Nokia","Note5",17000,2021,32,12,64,"SnapDragon");
    M.push_back(temp);

    temp.SetData("RedMI","Note7Pro",20000,2020,64,4,64,"SnapDragon");
    M.push_back(temp);

    temp.SetData("MicroMax","10i",12000,2021,32,4,64,"SnapDragon");
    M.push_back(temp);

    temp.SetData("Iphone","5s",20000,2017,16,4,32,"AppleM");
    M.push_back(temp);

    temp.SetData("OnePlus","9t",36000,2021,64,8,128,"SnapDragon");
    M.push_back(temp);

    temp.SetData("Samsung","GalaxyA51",22000,2021,48,8,64,"SnapDragon");
    M.push_back(temp);

    temp.SetData("RedMI","Note12",18000,2021,64,12,128,"SnapDragon");
    M.push_back(temp);
                                // /->Price purposely set Negative 
    temp.SetData("OnePlus","5t",-28000,2021,64,6,64,"SnapDragon");
    M.push_back(temp);*/
    }
    
    char choice='y';
    while(choice=='y'|| choice=='Y')
    {
        Mobile temp;
        
        cout<<"Enter Company : ";
        cin>> temp.company;

        cout<<"Enter ModelNo : ";
        cin>> temp.model_no;

        cout<<"Enter Price : ";
        cin>> temp.price;

        cout<<"Enter Year of MFG : ";
        cin>> temp.year_of_mfg;

        cout<<"Enter Camera : ";
        cin>> temp.camera;

        cout<<"Enter RAM : ";
        cin>> temp.RAM;

        cout<<"Enter Storage : ";
        cin>> temp.storage;

        cout<<"Enter Processor : ";
        cin>> temp.processor;

//Company, Modelno, Price, YearOfMfg, Camera, RAM, Storage, Processor
        Mobile newMobile;
        newMobile.SetData(temp.company,temp.model_no,temp.price,temp.year_of_mfg,temp.camera,temp.RAM,temp.storage,temp.processor);
        M.push_back(newMobile);
        cout<<endl;
        cout<<"Do you want to update more(y/n) : ";
        cin>>choice;
        cout<<endl;
    }
}

void DisplayMobile(vector<Mobile> &M)
{
    cout<<"Displaying Mobiles....\n\n";
    cout<<left<<setw(10)<<"Company"<<"  "<<left<<setw(10)<<"Model no"<<"  "<<setw(7)<<"Price"<<"  "<<"Year_of_mfg"<<"  ";
    cout<<setw(4)<<"RAM"<<"   "<<"Storage"<<"  "<<"Camera"<<"  "<<"Processor"<<endl<<endl;
    for(int i=0;i<M.size();i++)
            M[i].Display();
}

void SaveMobiles(vector<Mobile>&M)
{
    //cout<<"Writing in a file...."<<endl;

    fstream fout;
    fout.open("MobilesInfo.txt",ios::out);

    if(!fout) // Error Handling
    {perror("Error: ");exit(1);}

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
    //cout<<"Written Succesfully"<<endl;
}

void RetrieveMobiles(vector<Mobile>&M)
{
    //cout<<"Retrieving Mobiles ...."<<endl;
    int size;
    fstream fin;
    fin.open("MobilesInfo.txt",ios::in);

    if(!fin) // Error Handling
        {perror("Error: ");exit(2);}

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
    //cout<<"Retrieved Successfully"<<endl;
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

void summaryMobile(vector<Mobile> &M)
{
    //cout<<"summaryMobile Function Called************"<<endl;

    int c_iphone=0, c_samsung=0, c_MI=0, c_nokia=0, c_oneplus=0, c_micromax=0, c_oppo=0, c_vivo=0;
    for(int i=0;i<M.size();i++)
    {
        if(M[i].company=="Iphone")
            c_iphone++;
        else if(M[i].company=="Samsung")
            c_samsung++;
        else if(M[i].company=="RedMI" || M[i].company=="MI")
            c_MI++;
        else if(M[i].company=="Nokia")
            c_nokia++;
        else if(M[i].company=="OnePlus")
            c_oneplus++;
        else if(M[i].company=="MicroMax")
            c_micromax++;
        else if(M[i].company=="Oppo")
            c_oppo++;
        else if(M[i].company=="Vivo")
            c_vivo++;
    }
    cout<<"Total Count of Mobiles : "<<M.size()<<endl<<endl;
    cout<<"Iphones  : " << c_iphone   << endl;
    cout<<"Samsung  : " << c_samsung  << endl;
    cout<<"MI       : " << c_MI       << endl;
    cout<<"Nokia    : " << c_nokia    << endl;
    cout<<"OnePlus  : " << c_oneplus  << endl;
    cout<<"MicroMax : " << c_micromax << endl;
    cout<<"Oppo     : " << c_oppo     << endl;
    cout<<"Vivo     : " << c_vivo     << endl;
    cout<<endl<<endl;
}