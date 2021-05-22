
using namespace std;
int getValidPrice(int price)    
{
    //Now a days, price of mobile phones is not less than 3000
    try
    {
        if(price<3000)
        {
            throw(333);
        }
    }
    catch(int n)
    {
        if(n==333)
        {
            cout<<"Invalid Price!!"<<endl;
            cout<<"Enter Price again : ";
            cin>>price;
        }
        
    }
    
    return price;
}

int getValidYear(int year)    
{
    //Most of the screentouch mobiles(good) came after 2010
    try
    {
        if(year<2010)
        {
            throw(444);
        }
    }
    catch(int n)
    {
        if(n==444)
        {
            cout<<"Invalid Year!!"<<endl;
            cout<<"Enter Year again : ";
            cin>>year;
        }
    }
    
    return year;
}

class Electronics
{
    public:
    string company,model_no;   // company : Samsung   Model no: Galaxy M30 
    int price, year_of_mfg;
    //public:

    void SetData(string c,string m,int p, int y)
    {
        p = getValidPrice(p);
        y = getValidYear(y);
        
        company = c;
        model_no = m;
        price = p;
        year_of_mfg = y;
    }
   
    
    void Display()
    {
        cout<<left<<setw(10)<<company<<"  "<<left<<setw(10)<<model_no<<"  "<<setw(7)<<price<<"  "<<setw(11)<<year_of_mfg<<"  ";
    }
    
};
