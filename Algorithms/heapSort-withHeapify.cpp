#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Heap
{
    vector<T> vec;
    bool isMaxHeap;
    int heapLastIndex;
    void initHeap()
    {
        vec.push_back(0);
        for(int i=vec.size()-1;i>0;i--)
        {
            vec[i]=vec[i-1];
        }
    }
    void insertBehind(T element, int position)
    {
        for(int i=vec.size()-1;i>position;i--)
        {
            vec[i]=vec[i-1];
        }
        vec[position]=element;
    }
    bool checkViolation(int childIndex, int parentIndex)
    {
        if(childIndex<=heapLastIndex && parentIndex <=heapLastIndex)
        {
            if(isMaxHeap)
            {
                if(vec[childIndex]>vec[parentIndex]) return true; else return false;
            }
            else
            {
                if(vec[childIndex]< vec[parentIndex])return true; else return false;
            }
        }
        else return false;
    }

public:
    Heap(vector<T> elements, bool type): vec{elements},isMaxHeap{type},heapLastIndex{vec.size()}
    {
        initHeap();Heapify(heapLastIndex);
    }
    Heap(vector<T> elements): Heap{elements, true}{}
    Heap():Heap{{},true}{}
    ~Heap(){}
    void Insert(T element)
    {
        // Step-1: Add the element to the end of heap array
        // Step-2: Check if the parents of the node justify heap criterion
        // Step-3: Swap the parent and child till the criterion is not met
        vec.push_back(element);
        heapLastIndex++;
        int index = heapLastIndex;
        vec[heapLastIndex]=element;


        while(index/2 > 0 && checkViolation(index,index/2))
        {
            // if there is violation in heap criterion, swap the parent and child elements
            T element = vec[index];
            vec[index]=vec[index/2];
            index/=2;
            vec[index]= element;
        }

    }

    T Delete()
    {
        // Step-1: Replace the first element (master node) with the last element (last leaf node)
        // Step-2: Check for the heap criterion of master node and subsequent child nodes and rearrange heap
        // Step-3: Delete the last entry from vector and decrement the lastIndex of heap
        T element = vec[1];
        vec[1] = vec[heapLastIndex];
        int index = 1;
        while(2*index <heapLastIndex)
        {

            int childIndex1 = 2*index;
            int childIndex2 = 2*index + 1;
            bool swapChild1;
            if(isMaxHeap) swapChild1 = vec[childIndex1]> vec[childIndex2]? true:false;

            else swapChild1 = vec[childIndex1]< vec[childIndex2]? true:false;


            if(swapChild1)
            {
                T temp = vec[index];
                vec[index]= vec[childIndex1];
                vec[childIndex1]=temp;
                index = childIndex1;
            }
            else
            {
                T temp = vec[index];
                vec[index]= vec[childIndex2];
                vec[childIndex2]=temp;
                index=childIndex2;
            }
        }
        auto it= vec.begin();
        it+=heapLastIndex;
        vec.erase(it);
        heapLastIndex--;
        return element;
    }

    void Sort()
    {
        // Step-1: Store the current heap last element index (as it reduces with each deletion)
        // Step-2: Delete the first element of the heap and rearrange the remaining heap
        // Step-3: Append the deleted element to the end of heap list
        // Step-4: Update the heap last element index (to include all the elements in heap for display)
        int HI = heapLastIndex;
        for(int i=1;i<=HI;i++)
        {
            T element = Delete();
            insertBehind(element,heapLastIndex+1);
        }
        heapLastIndex = HI;
    }
    void Display(int endPosition=0)
    {
        cout<<"Heap Elements:- ";
        if(endPosition==0) endPosition = heapLastIndex; else endPosition=vec.size()-1;
        for(int i=1;i<=endPosition;i++) //i<=endPosition
        {
            cout<<vec[i]<<" ";
        }
        cout<<"\n";
    }
    void Heapify(int n)
    {

        if( n > 0 && (2*n < heapLastIndex))
        {
            bool isChild1 = vec[2*n] > vec[2*n+1]? true:false;
            if(isChild1 && checkViolation(2*n,n))
            {
                T temp = vec[2*n];
                vec[2*n]=vec[n];
                vec[n]=temp;
                Heapify(2*n);
            }
            else if(!isChild1 && checkViolation(2*n+1,n))
            {
                T temp = vec[2*n+1];
                vec[2*n+1]=vec[n];
                vec[n]=temp;
                Heapify(2*n+1);
            }
            Heapify(--n);
        }
        else if(n > 0 && (2*n > heapLastIndex))
        {
            Heapify(--n);
        }

    }
};

int main()
{
    int n,type;
    bool isMaxHeap = false;
    cout<<"Enter the number of elements in Heap:-\n";
    cin>>n;
    cout<<"Enter 1 for Max Heap; 0 for Min Heap\n";
    cin>>type;
    if(type==1)isMaxHeap = true;
    vector<float>vec;
    cout<<"Enter the elements into Heap:-\n";
    for(int i=0;i<n;i++)
    {
        float element;
        cin>>element;
        //h.Insert(element);
        vec.push_back(element);
    }
    Heap<float> h(vec,isMaxHeap);
    h.Display();
    h.Sort();
    cout<<"\nDisplay Sorted Heap:- ";
    h.Display();
    return 0;
}
