#include <iostream>
#include <vector>
using namespace std;
template<typename T>
bool compare(T& element1,T&element2,bool ascendingOrder=true)
{
    if(ascendingOrder)
    {
        if(element1 < element2) return true; else return false;
    }
    else
    {
        if(element1 > element2) return true; else return false;
    }
}
template<typename T>
void selectionSort(vector<T>& vec, bool ascendingOrder=true)
{
    int n = vec.size();
    for(int i=0;i<n;i++)
    {
        T element = vec[i];
        int minIndex=i;;
        bool change = false;

        for(int j=i+1;j<n;j++)
        {
            if(compare(vec[j],element,ascendingOrder))
            {
                minIndex = j;
                change = true;
                element = vec[j];
            }
        }
        if (change)swap(vec[i],vec[minIndex]);

    }
}
template<typename T>
void Display(vector<T>& vec)
{
    cout<<"Array Elements:- ";
    for(int i=0;i<vec.size();i++)cout<<vec[i]<<" ";
    cout<<"\n";
}
template<typename T>
T kSelect(vector<T>&vec,int k,bool isSmallest=true)
{
    unsigned n = vec.size();
    unsigned minIndex=0;

    for(unsigned i=0;i<k;i++)
    {
        T element = vec[i];
        bool change=false;
        for(unsigned j=i+1;j<n;j++)
        {
            if(compare(vec[j],element,isSmallest))
            {
                change=true;
                minIndex = j;
                element = vec[j];
            }

        }
        if(change) swap(vec[minIndex],vec[i]);
    }
    return vec[k-1];
}
int main()
{
    float n,e;
    int type,k;
    bool order=true;
    vector<float>arr;
    cout<<"Enter the number of elements in array\n";
    cin>>n;
    cout<<"Enter the elements in array\n";
    for(float i=0;i<n;i++)
    {
        cin>>e;
        arr.push_back(e);
    }
    cout<<"Enter the Kth element to be found\n";
    cin>>k;
    cout<<"Enter the nature of element: 1 for smallest and -1 for largest\n";
    cin>>type;
    if(type==-1) order=false;
    float element = kSelect(arr,k,order);
    cout<<"The "<<k<<"th element requested is: "<<element<<endl;
    Display(arr);
    order = true;
    cout<<"Mention the sorting order:- Enter 1 for Ascending,Enter -1 for Descending\n";
    cin>>type;
    if(type==-1)order=false;
    selectionSort(arr,order);
    Display(arr);

    return 0;
}
