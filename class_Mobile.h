
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

    friend void refreshDatabase(vector <Mobile> M);
    friend void RetrieveDatabase(vector<Mobile>&M);
};
