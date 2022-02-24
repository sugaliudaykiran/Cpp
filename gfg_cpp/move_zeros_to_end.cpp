#include<bits/stdc++.h>
using namespace std;

// Navie_Solution :-            TC --> O(N_square)..
void moves_zero(int ar[], int n){
    for(int i=0; i<n; i++){
        if (ar[i] == 0){                    // Element is Zero then Search and Swap..
            for (int j=i+1; j<n; j++){      // searching positive number on right side of 'i'..
                if (ar[j] != 0){
                    swap(ar[i], ar[j]);
                }
            }
        }
    }
}
// Efficient_Solution :-  TC -> O(N) and AS --> O(1).. Using One travesal..

void move(int ar[], int n){
    int count = 0;
    for (int i=0; i<n; i++){        
        if (ar[i] != 0){        // Here we can see A[i] == 0 --> Ignore, A[i] != 0 is Needed..
            swap(ar[i], ar[count]);
            count++;
        }
    }
}



int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // moves_zero(ar, n);
    move(ar,n);
    for (int i=0; i<n; i++){
        cout << ar[i] << " ";
    }

    return 0;
}