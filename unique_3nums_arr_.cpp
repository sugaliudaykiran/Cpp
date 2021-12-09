#include<bits/stdc++.h>
using namespace std;

int setBit(int n, int pos){
    return (n | (1 << pos));
}

bool getBit(int n, int pos){
    return ((n & (1 << pos))!= 0);    
}

int unique(int ar[], int n){
    int result = 0;

    for (int i=0; i<64; i++){
        int sum = 0;
        for (int j=0; j<n; j++){
            if (getBit(ar[j], i)){
                sum++;
            }
        }
        if (sum % 3 != 0){
            result = setBit(result, i);
        }
    }
    return result;
}
int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    cout << unique(ar, n) << endl;
    return 0;
}

// ex -> 10
// 1 2 3 4 1 2 3 1 2 3
// ans -> 4