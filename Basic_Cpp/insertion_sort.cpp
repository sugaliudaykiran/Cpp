#include<bits/stdc++.h>
using namespace std;

int Insertion_sort(int ar[], int n){
    for (int i = 1; i < n; i++){
        int current_pos = ar[i]; // Current_position is start from position '1'...
        int j = i-1;
        
        while(ar[j] > current_pos && j >= 0){
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = current_pos; /* here ar[j+1] because after the completed of while loop we need to update the first position of 'j'..
        */
    }

    for (int i=0; i < n; i++){
        cout << ar[i] << " ";
    }cout << endl;
    
}

int32_t main(){
    int n;
    cout << "n : ";
    cin >> n;

    int ar[n];

    for (int i=0; i<n; i++){
        cin >> ar[i];
    }
    Insertion_sort(ar, n);
    return 0;

}

/*
Insertion_Sort :- insert an element from unsorted array to its correct position in sorted array..


*/