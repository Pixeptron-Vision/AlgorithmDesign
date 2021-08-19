#include <iostream>
#include <vector>
using namespace std;
template<typename T,typename T1>
void insertionSortF(T& arr)
{
    int N = arr.size();

    for(int i=1;i<N;i++)
    {
        T1 element1,element2;
        bool replace = false;
        for(int j=0;j<=i;j++)
        {
            //cout<<"Before:- "<<j<<" "<<i<<" "<<arr[j]<<" "<<arr[i]<<" Element-1:- "<<element1<<", Element-2:- "<<element2<<endl;
            if(replace)
            {
                element2 = arr[j];
                arr[j]=element1;
                element1 = element2;
            }
            if(arr[j]> arr[i] && !replace)
            {
                replace = true;
                element1 = arr[j];
                arr[j]=arr[i];
                arr[i]=element1;
            }
            //cout<<"After:-  "<<j<<" "<<i<<" "<<arr[j]<<" "<<arr[i]<<" Element-1:- "<<element1<<", Element-2:- "<<element2<<endl;

        }

    }

}
template<typename T>
bool checkViolaton(T& element1,T&element2,bool ascendingOrder=true)
{
    //cout<<element1<<" "<<element2<<endl;
    if(ascendingOrder)
    {
        if(element1 > element2) return true; else return false;
    }
    else
    {
        if(element1 < element2) return true; else return false;
    }
}
template<typename T>
void insertionSort(vector<T>& vec,bool ascendingOrder=true)
{
    int n = vec.size();

    for(int i=1;i<n;i++)
    {
        int j = i-1;
        T element = vec[i];
        while( j >=0 && checkViolaton(vec[j],element,ascendingOrder))
        {
            vec[j+1]=vec[j];
            j--;
        }
        vec[j+1]=element;
    }

}
int main()
{
    float n,e;
    int type;
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
    cout<<"Mention the sorting order:- Enter 1 for Ascending,Enter -1 for Descending\n";
    cin>>type;
    if(type==-1)order=false;
    //insertionSortF<vector<float>,float>(arr);
    insertionSort(arr,order);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
