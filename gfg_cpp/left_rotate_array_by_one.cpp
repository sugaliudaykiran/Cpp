#include<bits/stdc++.h>
using namespace std;
//                          TC - > 0(N)..   AS --> 0(1)..
void LRO(int ar[], int n){
    int temp = ar[0];
    for (int i=1; i<n; i++){        // Counter - Clock Wise rotation..
        ar[i-1] = ar[i];
    }ar[n-1] = temp;
}

// Rotate by K - Time..     TC --> 0(N * k)..   AS -> 0(1)..
void k_rotate(int ar[], int n, int k){
    for (int i=0; i<k; i++){
        LRO(ar, n);
    }
}

// Rotate by K - Time.. at TC --> 0(N)..Ignoring the k_loops..and AS --> 0(k)..
void k_rotates(int ar[], int n, int k){
    int temp[k];
    for (int i=0; i<k; i++){
        temp[i] = ar[i];
    }
    for (int i=k; i<n; i++){
        ar[i-k] = ar[i];
    }
    for (int i=0; i<k; i++){
        ar[n-k+i] = temp[i];
    }
}

//Efficient_Solution :-  
void rotate(int ar[], int start, int end){
    while(start < end){
        swap(ar[start], ar[end]);
        start++;
        end--;
    }
}
//  By TC -> k + n-k + n ==> 0(2N) ==> 0(N).. and AS --> 0(1)..
void k_rot(int ar[], int n, int k){
    rotate(ar, 0, k-1);
    rotate(ar, k, n-1);
    rotate(ar, 0, n-1);
}

int32_t main(){
    int n, k;
    cin >> n >> k;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }
    
    // LRO(ar, n);
    // k_rotate(ar, n, k);
    // k_rotates(ar, n, k);
    k_rot(ar, n, k);
    for (int i=0; i<n; i++){
        cout << ar[i] << " ";
    }
    return 0;
}