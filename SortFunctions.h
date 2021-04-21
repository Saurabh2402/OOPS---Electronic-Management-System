using namespace std;


        ///Time Complexity is O(n*log(n)) base 2 in worst case
        ///Hybrid of quick sort, heap sort, introsort

bool cmpfunc1(Mobile &M1,Mobile &M2)
    {return  M1.price < M2.price;}
void Sort_by_Price(vector<Mobile> &M)
    {sort(M.begin(),M.end(),&cmpfunc1);}

bool cmpfunc2(Mobile &M1,Mobile &M2)
    {return  M1.year_of_mfg < M2.year_of_mfg;}
void Sort_by_Year_of_mfg(vector<Mobile> &M)
    {sort(M.begin(),M.end(),&cmpfunc2);}

bool cmpfunc3(Mobile &M1,Mobile &M2)
    {return  M1.RAM < M2.RAM;}
void Sort_by_RAM(vector<Mobile> &M)
    {sort(M.begin(),M.end(),&cmpfunc3);}

bool cmpfunc4(Mobile &M1,Mobile &M2)
    {return  M1.storage < M2.storage;}
void Sort_by_Storage(vector<Mobile> &M)
    {sort(M.begin(),M.end(),&cmpfunc4);}

bool cmpfunc5(Mobile &M1,Mobile &M2)
    {return  M1.camera < M2.camera;}
void Sort_by_Camera(vector<Mobile> &M)
    {sort(M.begin(),M.end(),&cmpfunc5);}