#include <iostream>
#include <vector>
using namespace std;

template<typename T>
T merge(T& arr1, T&arr2)
{
  int total_length = arr1.size() + arr2.size();
  T res(total_length);
  int i{0},j{0},k{0};
  while(i< arr1.size() && j < arr2.size())
  {
    if(arr1[i] <= arr2[j])
    {
      res[k] = arr1[i];
      k++;
      i++;
    }
    else
    {
      res[k] = arr2[j];
      k++;
      j++;
    }
  }
  while( i < arr1.size() && k < total_length)
  {
    res[k]=arr1[i];
    k++;
    i++;
  }
  while(j < arr2.size() && k < total_length)
  {
    res[k]=arr2[j];
    k++;
    j++;
  }
  return res;
}
template<typename T>
void copyVec(T& arr1, T& arr2, int low, int high)
{
  for(int i=low, j=0; i<= high; i++,j++)
  {
    arr2[j] = arr1[i];
  }
}
template<typename T>
T mergeSort(T v, int low, int high)
{
  int length = high-low+1;
  if(length < 2)
  {
    return v;
  }
  else
  {
    int mid = high / 2;
    // Create the left copy of vector
    T arr1(mid-low+1,0);
    T arr2(high-mid,0);
    auto it1 = v.begin();
    auto it2 = v.begin();
    it2 += mid+1;
    it1 +=mid+1;
    arr1.assign(v.begin(),it1);
    arr2.assign(it2,v.end());

    //copyVec(v,arr1,low,mid);
    //copyVec(v,arr2,mid+1,high);
    cout<<" Low:- "<<low<<" High:- "<<high<<" Mid:- "<<mid<<endl;
    // first recursive call
    T left = mergeSort(arr1,low, mid);
    T right = mergeSort(arr2,low,high-mid-1);
    T result = merge(left, right);
    return result;
  }

}
int main()
{
    vector<int> v,sorted;
    int n,j;
    cout<<"Enter the size of vector\n";
    cin>>n;
    cout<<"Enter the vector elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>j;
        v.push_back(j);
    }
    sorted = mergeSort(v,0,n-1);
    for(auto it=sorted.begin();it!=sorted.end();it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}
