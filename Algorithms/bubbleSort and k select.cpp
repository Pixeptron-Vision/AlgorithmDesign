#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void bubbleSort(vector<T>& vec, bool ascendingOrder=true)
{
    unsigned n = vec.size();
    for(unsigned i=0;i<n;i++)
    {
        for(unsigned j=0;j<n-1-i;j++)
        {
            if(ascendingOrder)
            {
                if(vec[j]>vec[j+1])
                {
                    swap(vec[j],vec[j+1]);
                }
            }
            else
            {
                if(vec[j]<vec[j+1])
                {
                    swap(vec[j],vec[j+1]);
                }

            }
        }
    }
}

template<typename T>
void bubbleSortAdaptive(vector<T>&vec,bool ascendingOrder=true)
{
    unsigned n = vec.size();
    bool noSwap=true;
    for(unsigned i=0;i<n;i++)
    {
        for(unsigned j=0;j<n-1-i;j++)
        {
            if(ascendingOrder)
            {
                if(vec[j]>vec[j+1])
                {
                    swap(vec[j],vec[j+1]);
                    noSwap=false;
                }
            }
            else
            {
                if(vec[j]<vec[j+1])
                {
                    swap(vec[j],vec[j+1]);
                    noSwap = false;
                }
            }
        }
        if(noSwap)
        {
            break;
        }
    }
}
template<typename T>
bool checkSorted(vector<T>vec,bool ascendingOrder=true)
{
    unsigned n = vec.size();
    for(unsigned i=0;i<n-1;i++)
    {
        if(ascendingOrder)
        {
            if(vec[i]> vec[i+1])
            {
                return false;
            }
        }
        else
        {
            if(vec[i] < vec[i+1])
            {
                return false;
            }
        }
    }
    return true;
}

template<typename T>
T kSelect(vector<T>&vec, int k,bool ascendingOrder=true)
{
    unsigned n = vec.size();
    for(unsigned i=0;i<k;i++)
    {
        for(unsigned j=0;j<k-1-i;j++)
        {
            if(ascendingOrder)
            {
                if(vec[j]>vec[j+1])
                {
                    swap(vec[j],vec[j+1]);
                }
            }
            else
            {
                if(vec[j] < vec[j+1])
                {
                    swap(vec[j],vec[j+1]);
                }
            }
        }
    }
    if(ascendingOrder) return vec[k-1]; else return vec[n-1-k];

}
template<typename T>
void Display(vector<T>&vec)
{
    for(auto it=vec.begin();it!=vec.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<"\n";
}
int main()
{
    int n,type,k;
    float num;
    bool order= true;
    vector<float>vec;
    cout<<"Enter the number of elements\n";
    cin>>n;
    cout<<"Enter the elements\n";
    for(unsigned i=0;i<n;i++)
    {
        cin>>num;
        vec.push_back(num);
    }

    cout<<"Checking if array is sorted:...\n";
    bool result = checkSorted(vec,order);
    if(result)
    {
        cout<<"The Array is sorted\n";
    }
    else
    {
        cout<<"The Array is not Sorted\n";
    }
    cout<<"Enter the Kth element to be found\n";
    cin>>k;
    cout<<"Enter the nature of element: 1 for smallest and -1 for largest\n";
    cin>>type;
    if(type==-1) order=false;
    float element = kSelect(vec,k,order);
    cout<<"The "<<k<<"th element requested is: "<<element<<endl;
    order = true;
    cout<<"Pick the kind of sorting to be performed: Enter 1 for ascending order and -1 for descending order\n";
    cin>>type;
    if(type==-1) order=false;
    cout<<"Sorting the array in the order suggested\n";
    bubbleSort(vec,order);
    Display(vec);
    cout<<"Sorting the array in opposite order\n";
    order =!order;
    bubbleSortAdaptive(vec,order);
    Display(vec);


    return 0;
}
