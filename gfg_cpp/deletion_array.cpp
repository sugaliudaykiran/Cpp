#include<bits/stdc++.h>
using namespace std;

int dele_Element(int ar[],  int n, int k){      // TC --> 0(N)..
    int i = 0;
    for(i=0; i<n; i++){
        if (ar[i] == k){        // Iterate upto the k_element..
            break;
        }
    }
    
    if (n == i){
        return n;
    }                       // Hence the element is Not Deleted..

    for (int j=i; j<n; j++){
        ar[j] = ar[j+1];
    }
    return (n-1);       // Hence the element is deleted..
}

int32_t main(){
    int n, k;
    cin >> n >> k;  // if N = 5, k = 3..It delete only the first occurance of array..
    
    int ar[n]= {1,2,3,4,5};
    
    cout << dele_Element(ar, n, k) <<endl;
}