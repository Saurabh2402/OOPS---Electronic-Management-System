using namespace std;


        ///Time Complexity is O(n*log(n)) base 2 in worst case
        ///Hybrid of quick sort, heap sort, introsort

//****************************************Mobile Sort Functions
bool M_cmpfunc1(Mobile &M1,Mobile &M2)
    {return  M1.price < M2.price;}
void M_Sort_by_Price(vector<Mobile> &M)
    {sort(M.begin(),M.end(),&M_cmpfunc1);}

bool M_cmpfunc2(Mobile &M1,Mobile &M2)
    {return  M1.year_of_mfg < M2.year_of_mfg;}
void M_Sort_by_Year_of_mfg(vector<Mobile> &M)
    {sort(M.begin(),M.end(),&M_cmpfunc2);}

bool M_cmpfunc3(Mobile &M1,Mobile &M2)
    {return  M1.RAM < M2.RAM;}
void M_Sort_by_RAM(vector<Mobile> &M)
    {sort(M.begin(),M.end(),&M_cmpfunc3);}

bool M_cmpfunc4(Mobile &M1,Mobile &M2)
    {return  M1.storage < M2.storage;}
void M_Sort_by_Storage(vector<Mobile> &M)
    {sort(M.begin(),M.end(),&M_cmpfunc4);}

bool M_cmpfunc5(Mobile &M1,Mobile &M2)
    {return  M1.camera < M2.camera;}
void M_Sort_by_Camera(vector<Mobile> &M)
    {sort(M.begin(),M.end(),&M_cmpfunc5);}

void M_Sort(vector<Mobile> &M)
{
    cout<<"1: Sort by Price"<<endl;
    cout<<"2: Sort by Year of Manufacturing"<<endl;
    cout<<"3: Sort by RAM"<<endl;
    cout<<"4: Sort by Storage"<<endl;
    cout<<"5: Sort by Camera"<<endl;

    cout <<"Enter your choice for Sorting : ";
    int choice;
    cin>>choice;

    switch(choice)
    {
        case 1:M_Sort_by_Price(M);break;
        case 2:M_Sort_by_Year_of_mfg(M);break;
        case 3:M_Sort_by_RAM(M);break;
        case 4:M_Sort_by_Storage(M);break;
        case 5:M_Sort_by_Camera(M);break;

        default :cout<<"Invalid Choice!!"<<endl;
    }
}
//****************************************************************************
//  --Not Working ?????
/*template<typename X>
bool cmpfunc(X &X1,X &X2)
    {return  X1.storage < X2.storage;}
template<typename X>
void Sort_by_Storage(vector<X> &arr)
    {sort(arr,arr+arr.size(),&cmpfunc);}
*/

//****************************************Laptop Sort Functions
bool L_cmpfunc1(Laptop &L1, Laptop &L2)
{return L1.price < L2.price;}
void L_Sort_by_Price(vector<Laptop> &L)
    {sort(L.begin(),L.end(),&L_cmpfunc1);}

bool L_cmpfunc2(Laptop &L1,Laptop &L2)
    {return  L1.year_of_mfg < L2.year_of_mfg;}
void L_Sort_by_Year_of_mfg(vector<Laptop> &L)
    {sort(L.begin(),L.end(),&L_cmpfunc2);}

bool L_cmpfunc3(Laptop &L1,Laptop &L2)
    {return  L1.RAM < L2.RAM;}
void L_Sort_by_RAM(vector<Laptop> &L)
    {sort(L.begin(),L.end(),&L_cmpfunc3);}

bool L_cmpfunc4(Laptop &L1,Laptop &L2)
    {return  L1.storage < L2.storage;}
void L_Sort_by_Storage(vector<Laptop> &L)
    {sort(L.begin(),L.end(),&L_cmpfunc4);}

bool L_cmpfunc5(Laptop &L1,Laptop &L2)
    {return  L1.gCard < L2.gCard;}
void L_Sort_by_GCard(vector<Laptop> &L)
    {sort(L.begin(),L.end(),&L_cmpfunc5);}


void L_Sort(vector<Laptop> &L)
{
    cout<<"1: Sort by Price"<<endl;
    cout<<"2: Sort by Year of Manufacturing"<<endl;
    cout<<"3: Sort by RAM"<<endl;
    cout<<"4: Sort by Storage"<<endl;
    cout<<"5: Sort by Graphics Card"<<endl;

    cout <<"Enter your choice for Sorting : ";
    int choice;
    cin>>choice;

    switch(choice)
    {
        case 1:L_Sort_by_Price(L);break;
        case 2:L_Sort_by_Year_of_mfg(L);break;
        case 3:L_Sort_by_RAM(L);break;
        case 4:L_Sort_by_Storage(L);break;
        case 5:L_Sort_by_GCard(L);break;

        default :cout<<"Invalid Choice!!"<<endl;
    }
}
//***************************************************************************L



void Sort(vector<Mobile>&M, vector<Laptop>&L)
{
    cout<<"1: Sort Mobiles"<<endl;
    cout<<"2: Sort Laptops"<<endl;

    int choice;
    cout<<"Enter your choice: ";
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
        case 1:M_Sort(M);break;
        case 2:L_Sort(L);break;

        default:cout<<"Invalid Input!!"<<endl;
    }

    
}