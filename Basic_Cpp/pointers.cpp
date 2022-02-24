#include<bits/stdc++.h>
using namespace std;

// pointer to pointer :-
int p_t_p(){
    int x;
    cin >> x;
    int* ptr = &x;
    cout << *ptr << endl;     // value of x..
    int** b_ptr = &ptr;
    cout << *b_ptr << endl;  // value of pointer..
    cout << **b_ptr << endl; // value of x..

    **b_ptr = 20;
    cout << x << endl;        // modify the value of x..
}

int32_t main(){
    // int n;
    // cin >> n;
    // int* aptr = &n;  // & -> for address and * ptr --> for pointer...
    
    // cout << aptr << endl;   // Address of n;
    // cout << *aptr << endl;  // value of n;
    // *aptr = 20;             // updating the n value using pointer.  
    // cout << n << endl;  // updated value of n.


    // int ar[] = {1, 10, 100};
    // cout << *ar << endl;

    // int* ptr = ar;  // here ar is address of first value of array.

    // cout << ptr << endl;  // address of first value of array

    // for (int i=0; i<3; i++){
    //     cout << *ptr << "  ";
    //     ptr++;
    // }cout << endl;

    // cout << "other_ways" << endl;
    
    // for (int i=0; i<3; i++){
    //     cout <<* (ar+i) << "  "; // ar --> index pointer of array
    // }

    p_t_p();
    

    return 0;
}