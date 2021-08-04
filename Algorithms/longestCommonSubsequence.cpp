#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str1,str2;
    cout<<"Enter the strings\n";
    cin>>str1;
    cin>>str2;
    int result=0;
    // Longest common subsequence algorithm
    // Solutuon using Dynamic Programming approach
    // Initialize the matrix first
    int length1 = str1.length();
    int length2 = str2.length();
    int arr[length1+1][length2+1];
    for(int i=0;i<=length2;i++)arr[0][i]=0;
    for(int i=0;i<=length1;i++)arr[i][0]=0;
    // set up the variables for iteration
    int i=1;
    int j=1;
    // Loop through the matrix; for each char in str1, find matches in str2
    for(auto it=str1.begin();it!=str1.end();it++)
    {
        j=1;
        for(auto it2=str2.begin();it2!=str2.end();it2++)
        {
            // If a match is found, set the element of matrix[i][j] to 1 + of it's left diagonal
            if(*it==*it2)
            {
                arr[i][j]= 1+arr[i-1][j-1];
            }
            // If a match is not found, set the element of matrix[i][j] to maximum amongs the top and left neighbors
            else {
                int v1 = arr[i-1][j];
                int v2 = arr[i][j-1];
                arr[i][j] = v1 > v2 ? v1:v2;
            }
            j++;
        }
        i++;
    }
    // Result of Longest Common Substring will be in the element, matrix[string_1_length][string2_length]
    result = arr[length1][length2];
    // Print the matrix for visualization
    for(int i=1;i<=length1;++i)
    {
        for(j=1;j<=length2;++j)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";

    }
    cout<<result<<endl;
    // Trace the LCS string result
    int stop = 0;
    i=length1;
    j = length2;
    string lcs = "";
    while(stop<=result)
    {
        //cout<<" ("<<i<<","<<j<<") ";
        //check the left neighbor, if its is same, move left
        if(arr[i][j-1]==arr[i][j])
        {
            j=j-1;
        }

        else
        {
            lcs+=str1[i];
            i--;
            j--;
            stop++;
        }


    }
    // Reverse the string to produce answer
    string lcsr=""; //after this statement, lcsr will contain \0 as first character in it
    for(int i=result;i>0;i--)
    {
        lcsr+=lcs[i];
    }
    cout<<"\nLCS:- "<<lcsr<<endl;
    return 0;
}
