#include<bits/stdc++.h>
using namespace std;
//                                                   TC ---> 0(N).. and AS --> 0(1)..
void reverse_arr(int ar[], int n, int start, int end){
    while(start < end){
        int temp = ar[start];
        ar[start] = ar[end];
        ar[end] = temp;
        start++;
        end--;
    }
}

int32_t main(){
    int n;
    cin >> n;

    int start = 0,end = n-1;
    
    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    reverse_arr(ar, n, start, end);
    for (int i=0; i<n; i++){
        cout << ar[i] << " " ;
    }
    cout << endl;
    return 0;
}