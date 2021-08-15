#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Heap
{
    vector<T> vec;
    bool heapTypeMax;
    int heapIndex;
    bool compare(int index1,int index2)
    {
        if(index1 <=heapIndex && index2 <=heapIndex)
        {
                if(heapTypeMax)
                {
                    if(vec[index1]> vec[index2]) return true; else return false;
                }
                else
                {
                    if(vec[index1]< vec[index2]) return true; else return false;
                }
        }
        else return false;

    }
    void rightShift(T element=0,int position=0)
    {
        vec.push_back(element);
        int endPosition = heapIndex;
        if(element > 0)
        {
            endPosition = vec.size()-1;
        }
        //cout<<"Before:- ";Display(vec.size());
        for(int i=endPosition;i>position;i--)
        {
            vec[i]=vec[i-1];
        }
        if(element>0)
        {
            vec[position]=element;
        }
        //cout<<"After:- ";Display(vec.size());

    }
    public:

        Heap(vector<T>elements,bool type):vec{elements},heapTypeMax{type},heapIndex{vec.size()} // Generic Template
        {
            rightShift();
        }
        Heap():Heap{{},true}
        {
            //rightShift();heapIndex=vec.size();
        }
        Heap(vector<T>elements):Heap{elements,true}
        {
            //heapIndex=vec.size();rightShift();
        }
        //Heap(vector<T>elements,bool type):Heap{elements,type,0}{};
        //Heap(vector<T>elements,bool type):vec{elements},heapTypeMax{type}{heapIndex=vec.size();rightShift();};

        ~Heap(){}
        void Insert(T element)
        {
            //inserting subroutine
            // Step-1: Add element at the end of array
            vec.push_back(0);
            heapIndex++;
            vec[heapIndex]=element;
            int index = heapIndex;
            //cout<<"HI:- "<<heapIndex<<" "<<vec[index]<<endl;

            // Step-2: Rearrange heap
            while(index/2 >0 && compare(index,index/2))
            {
                T temp=vec[index];
                vec[index]=vec[index/2];
                index/=2;
                vec[index]=temp;
                //cout<<"I:- "<<index<<" "<<vec[index]<<endl;
            }
        }
        T Delete()
        {
            /*deleting subroutine
            Step-1: Store the max heap element
            Step-2: Check the eligible child and replace max element with it
            Step-3: Continue step-2 till entire heap is rearranged
            Step-4: delete the redundant leaf at end of heap
            */
            T element = vec[1];
            int index = 1;
            vec[index]= vec[heapIndex];
            //cout<<"HI:- "<<heapIndex<<" "<<vec[index]<<endl;
            while(index*2 < heapIndex)
            {
                int childIndex1 = 2*index;
                int childIndex2 = 2*index + 1;
                bool swapChild1 = compare(childIndex1,childIndex2);
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
            auto it=vec.begin();
            it+=heapIndex;
            vec.erase(it);
            heapIndex--;
            return element;
        }
        void Sort()
        {
            /*heap sort subroutine
            Step-1 : Store the heap Length
            Step-2 : Remove max element and arrange heap
            Step-3 : Append the removed element in the end of vector and arrange vector
            Step-4 : Restore the length of heap to reflect sorted vector during display
            */
            int HI = heapIndex;
            while(heapIndex>1)
            {

                T element = Delete();
                //cout<<" HI:- "<<heapIndex<<" Ele:- "<<element<<endl;

                rightShift(element,heapIndex+1);
            }
            heapIndex=HI;
        }

        void Display(int endPosition=0)
        {
            cout<<"Heap Elements:- ";
            if(endPosition==0) endPosition = heapIndex; else endPosition=vec.size()-1;
            for(int i=1;i<=endPosition;i++)
            {
                cout<<vec[i]<<" ";
            }
            cout<<"\n";
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
    Heap<float> h({},isMaxHeap);
    cout<<"Enter the elements into Heap:-\n";
    for(int i=0;i<n;i++)
    {
        float element;
        cin>>element;
        h.Insert(element);
    }
    h.Display();
    h.Sort();
    cout<<"\nDisplay Sorted Heap:- ";
    h.Display();
    return 0;
}
