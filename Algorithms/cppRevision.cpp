#include <iostream>
#include <vector>

// Defining a class

// Defining a class and Union

// Defining a friend function

// Declaring a normal function

// Declaring a overloaded function

// Defining templates

int main()
{

    // Initializing Variables

    int age;
    int age1 = 21; // c style
    int age2(21); // constructor initialization
    int age3{21}; // c+11 list init. syntax

    // Initializing arrays

    int a[100] {0};
    int b[]{1,2,3};
    const int c{0};
    int d[c];

    // passing 1D - array by value
    // passing 1D - array by reference
    // passing 2D - array by value
    // passing 2D - array by reference
    // standard pointers
    // creating a linked list using memory

    // Vectors
    std::vector <int> va(10, 0); // a values initialized to zeros
    std::vector <int> vb{1,2,3}; // b values set to 1,2,3
    std::vector <int> vc(2); // vector c of length 2 ints initialized with zeros
    std::vector <char> vowels{'a','e','i','o','u'};

    //  Vector access
    std::cout<<va[0]<<vb.at(1)<<std::endl;
    // Vector add values
    vc.push_back(5); // at the back
    // at the front
    // in the middle

    // Vector remove values
    // at the front
    // at the back
    // in the middle
    // 2D vectors
    std::vector<std::vector<int>> array2D {{1,2,3},{4,5,6},{7,8,9}};
    array2D[0][0] = 20;
    std::cout<<array2D[0][0]<<std::endl;
    array2D.at(0).at(0)= 21;
    std::cout<<array2D.at(0).at(0)<<std::endl;

    std::cout<<std::boolalpha;// To print booleans at True/False


    // Convert string to numbers
    // Convert numbers to strings


    // Object pointers


    return 0;
}



