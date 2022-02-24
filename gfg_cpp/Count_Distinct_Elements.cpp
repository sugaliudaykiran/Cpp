#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

//      Navie - Solution :=
int count_s(int ar[], int n){   // TC --> O(N_square).. AS -> O(1)..
    int count = 0;
    for(int i=0; i<n; i++){
        bool rep = false;
        for (int j=0; j<i; j++){
            if (ar[j] == ar[i]){
                rep = true;
                break;
            }
        }
        if (!rep){
            count++;
        }
    }
    return count;
}

//  Efficient - Solution :=         TC --> 0(N)..  AS -> O(N)..
int cunt(int ar[], int n){
    unordered_set <int> s;      // here we declared "unordered_set <type> set_name"..
    for (int i=0; i<n; i++){
        s.insert(ar[i]);         // it insert as keys to set which are unique..
    }
    return s.size();              // returns size of set..
}

//  Improved - Efficient Solution :=        TC --> 0(N)..  AS -> O(N)..
int cunts(int ar[], int n){
    unordered_set <int> s(ar, ar+n);    // here (ar, ar+n) is an iterator which used in common constructor {begin_iterator, end_iterator}.. 
    return s.size();
}

int32_t main(){

    int n;
    cin >> n;

    int ar[n];

    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    cout << count_s(ar, n) << endl;

    return 0;
}