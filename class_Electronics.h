
using namespace std;

class Electronics
{
    public:
    string company,model_no;   // company : Samsung   Model no: Galaxy M30 
    int price, year_of_mfg;
    //public:

    void SetData(string c,string m,int p, int y)
    {
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
