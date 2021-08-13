#include <iostream>
#include <vector>
using namespace std;
template<typename T,typename T1>
void insertionSort(T& arr)
{
    int N = arr.size();

    for(int i=1;i<N;i++)
    {
        T1 element1,element2;
        bool replace = false;
        for(int j=0;j<=i;j++)
        {
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

        }

    }

}
int main()
{
    float n,e;
    vector<float>arr;
    cout<<"Enter the number of elements in array\n";
    cin>>n;
    cout<<"Enter the elements in array\n";
    for(float i=0;i<n;i++)
    {
        cin>>e;
        arr.push_back(e);
    }
    insertionSort<vector<float>,float>(arr);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
