/*
    Bucket Sort :=  {Hashing with chaining..}
    standard Bucket Sort algorithm and its applications.

    1) Consider a Situation where we have numbers "Uniformly distributed" in range from 1 to 10_toPower_8 How do we sort efficiently..
    2) Consider another Situation when we have Floating Point Numbers "Uniformly distributed" in range from 0.0 to 1.0 ..

    Idea to Solve :-
    1) First we need create the Individual Buckets which has "a range" of element and insert based on the range..
    2) Then Sort the Individual Buckets .. using Insertion Sort..{Because when no of element is smaller numbers..}
    3) Finally join all elements of the Individual Buckets..


    Assuming K ~~{Similiar to } N..
    Best Case :- Data is Uniformly Distributed ---> O(N).. in which each item has each Bucket..
    Worst Case :- Assuming all items go into a single Bucket
                 If we use Insertion Sort to sort the Individual Buckets, Then TC --> O(N_square)..
                 If we Use O(N_LogN) algorithm to sort the Individual Buckets, Then TC --> O(N_logN)..
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void b_s(int ar[], int n, int k){
    //  Find Maximum Value..
    int maxs = ar[0];
    for (int i=1; i<n; i++){
        maxs = max(maxs, ar[i]);
    }

    maxs++;
    vector <int> btk[k];    // Filling the Bucket..
    for (int i=0; i<n; i++){
        int bi = (k * ar[i])/maxs;      // Matching each element and pushing into Right Bucket..
        btk[bi].push_back(ar[i]);
    }

    for (int i=0; i<k; i++){
        sort(btk[i].begin(), btk[i].end());     // Sort each Buckets.. Here we used Sort but in case of small elements in array we can Use Insertion sort..
    }                                                                             // Sort takes TC as 0(N_logN)..  and .. Insertion takes TC as O(N)..              

    int idx = 0;
    for (int i=0; i<k; i++){
        for (int j=0; j < btk[i].size(); j++){      // Join Buckets.. which are sorted..
            ar[idx++] = btk[i][j];
        }
    }
}

int32_t main(){
    int n, k;
    cin >> n >> k;  // K is number of Buckets..

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    b_s(ar, n, k);

    for (int s : ar){
        cout << s << " ";
    }
    return 0;
}
