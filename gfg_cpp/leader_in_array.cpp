// Leader means element 'i' towards right element should be lesser..than i..

#include<bits/stdc++.h>
using namespace std;

void leader(int ar[], int n){       //  TC --> 0(N_square)..
    
    for (int i=0; i<n; i++){
        bool flag = true;
        for (int j=i+1; j<n; j++){
            if (ar[i] <= ar[j]){
                flag = false;
                break;
            }
        }
        if (flag){
            cout << ar[i] << " ";
        }
    }
}

void leader_reverse(int ar[], int n){       // TC ---> 0(N)..if u want result the left-right order store and reverse it..

    int curr_ldr = ar[n-1];
    cout << curr_ldr << " ";        // Last element always a leader..

    for (int i=n-2; i>=0; i--){     // From N-2 to 0 Index..
        if (ar[i] > curr_ldr){      // Compare the Curr_Ide..with current Index..
            curr_ldr = ar[i];       // Update the Curr_Ide..
            cout << curr_ldr << " ";
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

    // leader(ar, n);
    leader_reverse(ar, n);
    return 0;
}