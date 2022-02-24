#include<bits/stdc++.h>
using namespace std;
                    
                    //  Tc --> O(N) and Insert at end will be TC -> O(1) .. and  beginning  TC -> 0(N)..

int insert(int ar[], int cap, int n, int ele, int pos){
    if (n == cap){
        return n;
    }
    int index = pos - 1;

    for (int i=n-1; i <= index; i++){
        ar[i+1] = ar[i];
    }
    // Insert the element at the Index..    

    ar[index] = ele;

    return n+1;
}


int32_t main(){
    int cap = 5 ;    // capacity of an Array ..
    int n = 4;       // elements in array..
    int ele, pos ;     // Inserting the Element.. and position in array..
    cin >> ele >> pos;

    int ar[cap] = {1, 2, 3, 4 };

    if (insert(ar, cap, n, ele, pos) == cap){
        cout << "Array is Full" << endl;
    }
    else
        cout << "Array is Not Full" << endl;
    return 0;
}