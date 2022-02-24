/*
    Meeting the maximum guests :=       0 <= ar[], dep[] <= 2359 ==> 0:00 to 23:59..
        you are given arrival and departure times of the guests,
        you need to find the time to go to the pary so that you can meet maximum people.

    ex -> arrival[]  -> {900, 940}..        ==> {9:00 to 9:40}  
        departure[]  -> {1000, 1030}..      ==> {10:00 to 10:30}
            result   -> {940, 1000}..       ==> {9:40 to 10:00} --> In this time we can meet Both the arrivals..
        Output --> "2"..  {Return Integer Value..}
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Solution :=        TC --> O(N_LogN)..
int meet_min(int ar[], int dep[], int n){   
    sort(ar, ar+n);
    sort(dep, dep+n);

    int i=1, j=0, curr = 1, res = 1;        // "i" start from 1.. count of current person.. 
    while (i < n && j < n){             // i for Arrival..      j for Departure..
        if (ar[i] <= dep[j]){           // if arrival is less or equal.. then departure.. then increment curr..count..and increment arrival count..
            curr++;
            i++;
        }
        else {          // If arrival is greater than departure then decrement the current count and increment the departure count..
            curr--;
            j++;
        }
        res = max(res, curr);       // Maximum of the arrival sequential then return it..
    }
    return res;
}

int32_t main(){
    int n;
    cin >> n;

    int ar[n];      //  arrival time..
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    int dep[n];         // departure time..
    for (int i=0; i<n; i++){
        cin >> dep[n];  
    }

    cout << meet_min(ar, dep, n);
    return 0;
}
