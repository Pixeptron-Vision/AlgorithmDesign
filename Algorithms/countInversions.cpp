#include <iostream>
#include <vector>
using namespace std;
vector<int> split_check(vector<int>v1, vector<int>v2,int & count,bool & flag)
{
     int L1 = v1.size();
     int L2 = v2.size();
     int i{0},j{0},k{0};
     //cout<<"L1:- "<<L1<<", L2:- "<<L2<<" "<<v1[0]<<":"<<v2[0]<<endl;
     vector<int>res(L1+L2);
     while( i<L1 && j < L2)
     {
         if(v1[i] <= v2[j])
         {
             res[k]=v1[i];
             k++;
             i++;
             int diff = (v2[j]-v1[i-1]);
             /*
             cout<<v1[i-1]<<","<<v2[j]<<":Diff:- "<<diff<<": Count:- "<<count<<endl;

             if( diff > 2 && !flag)
             {
                 cout<<"Too chaotic"<<endl;
                 flag = true;
             }
             */
         }
         else {
             res[k]=v2[j];
             j++;
             k++;
             int skip = L1-i;

             int diff = (v1[i]-v2[j-1]);

             //cout<<v1[i]<<","<<v2[j-1]<<":Diff:- "<<diff<<": Count:- "<<count<<", Skip:- "<<skip<<endl;
             count = count + skip;
             /*
             if( diff > 2 && !flag)
             {
                 cout<<"Too chaotic"<<endl;
                 flag = true;
             }
             */

         }

     }
     int total_length = L1+L2;
     while(i< L1 && k < total_length)
     {
         res[k]=v1[i];
         k++;
         i++;
     }
     while(j< L2 && k < total_length)
     {
         res[k]=v2[j];
         k++;
         j++;
     }
    /*
    for(auto it=v1.begin();it!=v1.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<"\n";
    for(auto it=v2.begin();it!=v2.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<"\n";
    for(auto it=res.begin();it!=res.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<"\n";
     */
     return res;
}

vector<int> merge_n_count(vector<int> v, int low, int high,int& count,bool &flag)
{
     int bribes{0};
     bool illegal=false;
     int length = high-low+1;
     if (length < 2)
     {
         //cout<<"Return:- "<<v[0]<<endl;
         return v;
     }
     else
     {
        int mid = high/2;
        vector<int>arr1(mid-low+1,0);
        vector<int>arr2(high-mid,0);
        //cout<<" Low:- "<<low<<" High:- "<<high<<" Mid:- "<<mid<<endl;
        arr1.assign(v.begin(),v.begin()+mid+1);
        arr2.assign(v.begin()+mid+1, v.end());
        vector<int>left = merge_n_count(arr1, low, mid, bribes, illegal);

        vector<int>right = merge_n_count(arr2, low, high-mid-1, bribes, illegal);

        vector<int>result=split_check(left, right,bribes, illegal);
        count += bribes;
        flag = illegal;
        /*
        for(auto it=result.begin();it!=result.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<"\n";
        */
        return result;

     }
}

int main()
{
    vector<int> v,sorted;
    bool illegal = false;
    int result = 0;
    int n,j;
    cout<<"Enter the size of vector\n";
    cin>>n;
    cout<<"Enter the vector elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>j;
        v.push_back(j);
    }

    sorted = merge_n_count(v,0,n - 1,result, illegal);
    cout<<"Inversions Count:- "<<result<<endl;
    cout<<"Sorted Array:-  ";
    for(auto it=sorted.begin();it!=sorted.end();it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}
