#include <iostream>
#include <vector>

using namespace std;

template <typename T1, typename T2 >
int binarySearch(T1 arr,T2 query, int low, int high)
{
    if(low < high)
    {
        int index=0;
        int middle = (high+low)/2;

        //cout<<low<<" "<<high<<" "<<middle<<endl;
        if(arr[middle]==query)
        {
            return middle;
        }
        else if(arr[middle]>query)
        {
            int index = binarySearch(arr,query,low,middle-1);
            return index;
        }
        else if(arr[middle]< query)
        {
            int index = binarySearch(arr,query,middle+1,high);
            return index;
        }
    }
    else
    {
        return -1;
    }

}

int main()
{
    int n;
    float e;
    vector<float>arr;
    cout<<"Enter the number of elements\n";
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>e;
        arr.push_back(e);
    }
    cout<<"Enter the query\n";
    cin>>e;
    int index = binarySearch(arr,e,0,n-1);
    if (index!=-1)
    {
        cout<<"The query is available at index:- "<<index<<"\n";
    }
    else
    {
        cout<<"The query is not available\n";
    }
    return 0;
}
