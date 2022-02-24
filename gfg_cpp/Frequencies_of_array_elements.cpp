#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//      Navie - Solution :=     TC --> O(N_square).. AS -> O(1)..
void freq(int ar[], int n){
    for (int i=0; i<n; i++){
        bool flag = false;          
        for (int j=0; j<i; j++){    // Check if seen before..
            if (ar[j] == ar[i]){
                flag = true;
                break;
            }
        }
        if (flag){                  // If seen then ignore..
            continue;
        }
        int feq = 1;
        for (int k=i+1; k<n; k++){      // If not seen before count frequency..
            if (ar[k] == ar[i]){
                feq++;
            }
        }
        cout << ar[i] << " " << feq << endl;
    }
}

        // Efficient - Solution :=      TC --> 0(N).. AS -> O(N)
void freqs(int ar[], int n){
    unordered_map <int, int> um;    // uses hashing which follows unordered way..

    for (int i=0; i<n; i++){
        um[ar[i]]++;
    }

    // for (auto e: um){
    //     cout << e.first << " " << e.second << endl;
    // }                                                    // another way using iterator..

    for (auto it = um.begin(); it != um.end(); it++){
        cout << it-> first << " " << it-> second << endl;
    }

}

/*
    Here we can traverse through array elements by every traverse we print item and its frequency..
        to avoid the frequency of duplicate we assign the item after it prints to -1..
*/


int32_t main(){

    int n;
    cin >> n;

    int ar[n];

    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // freq(ar, n);

    freqs(ar, n);
    return 0;
}