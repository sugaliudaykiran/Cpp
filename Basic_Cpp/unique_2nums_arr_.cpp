#include<bits/stdc++.h>
using namespace std;

int set_bit(int n, int pos){
    return ((n & (1 << pos))!= 0);
}
void unique_2(int ar[], int n){
    int xorsum = 0;
    for (int i=0;i<n;i++){
        xorsum ^= ar[i];
    }
    int temp = xorsum;
    int setbit = 0;
    int pos = 0;
    
    while (setbit != 1){ // upto 1..
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1; // right-shit..towards '<-'
    }
    int new_xor = 0;
    for (int i=0; i<n; i++){
        if (set_bit(ar[i], pos-1)){
            new_xor = new_xor ^ ar[i];
        }
    } 
    cout << new_xor << endl;
    cout << (new_xor ^ temp) << endl;
}

int32_t main(){
    int n;
    cin >> n;
    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }
    unique_2(ar, n);
    return 0;
}

/*

1) get the xorsum of the array..
2) result xorsum we need to check the right-most bit and check in the array in position of 
    right-most-bit element and do xorsum..
3) after the doing xorsum we will get first_unique one and doing the xor to the first_unique to xorsum will get 
    secound unique element..

*/