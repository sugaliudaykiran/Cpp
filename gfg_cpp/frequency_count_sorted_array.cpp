#include<bits/stdc++.h>
using namespace std;
    //                      Array should be sorted.. TC --> 0(N)..
void freq(int ar[], int n){
    int fq = 1;
    int i = 1;
    while(i < n){
        while(i < n && ar[i] == ar[i-1]){
            fq++;
            i++;
        }
        cout << ar[i-1] << " : " << fq << endl;
        fq = 1;
        i++; 
    }                           // If in case n == 1 or for the last element..
    if(n == 1 || ar[n-1] != ar[n-2]){      
           cout << ar[n-1] << " : " << fq << endl;
    }
       
}

int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    freq(ar, n);
    return 0;
}