#include<bits/stdc++.h>
using namespace std;

// ref :- https://www.geeksforgeeks.org/structures-unions-and-enumerations-in-cpp/

struct Complex
{
    int real;
    int imginary;
};


int32_t main()
{
    struct Complex N1, N2, N3;

    cin >> N1.real >> N1.imginary;
    cin >> N2.real >> N2.imginary;

    N3.real = N1.real + N2.real;
    N3.imginary = N1.imginary + N2.imginary; 

    cout << N3.real <<  "+"  << N3.imginary << "i";
    return 0;
}