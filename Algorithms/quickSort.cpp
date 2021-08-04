#include <iostream>
#include <utility>
#include <vector>
#include <random>
using namespace std;
template<typename T>
void Display(const T& A)
{
    for(int i=0;i<A.size();i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}
template<typename T1>
int Partition(T1& A, int low, int high)
{
    /*
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(low, high); // define the range
    //Random Gen code source: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
    int rand = distr(gen);
    cout<<"Random Num:- "<<rand<<endl;
    */
    int pivot = A[low];
    int j;
    int i=low+1;
    j=low+1;
    while(j<=high)
    {
        if(A[j]<=pivot)
        {
            if(i<j)
            {
                int temp = A[i];
                A[i]=A[j];
                A[j]=temp;
            }

            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    A[low] = A[i-1];
    A[i-1] = pivot;

    cout<<"Part:- Low-"<<low<<" High-"<<high<<" Part:-"<<i<<endl;
    Display(A);
    return i;
}

template<typename T>
void quickSort(T& A,int low, int high)
{
    int length = high-low+1;
    if(length>2)
    {
        int barrier = Partition<T>(A,low,high);
        quickSort(A,low,barrier-1);
        quickSort(A,barrier+1,high);
    }

}



int main()
{
    int n, num;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        v.push_back(num);
    }
    quickSort(v,0,n-1);
    Display(v);
    return 0;
}
