// Count inversions in Array :=
//      problem of taking an unsorted array and counting the inversions in it. 
//         There are two conditions for the  elements to be inverse:
//                  **   arr[i] > arr[j]
//                  **      i < j

#include<bits/stdc++.h>
using namespace std;

// Navie - Solution :-          TC --> O(N_square..)
void counts(int ar[], int n){
    int c = 0;
    for (int i=0; i < (n-1); i++){    // Upto last 2 element for the reason is for the last element(N-1) there is additional element..
        for (int j=i+1; j<n; j++){
            if (ar[i] > ar[j]){
                c++;
            }
        }
    }
    cout << c << endl;
}

/* Efficient - Solution :-      TC --> O(N_logN)..
        Every inversion (x, y) where x > y has possibilites 
        a) Both x and y are in left half..
        b) Both x and y are in right half..
        c) x is in left half and  y is in right half..
*/

int count_merge(int ar[], int low, int mid, int high){
    int n1 = mid - (low+1), n2 = high - mid;    // Low may not be starts  from the Zero..
    int a[n1], b[n2];

    for (int i=0; i<n1; i++){
        a[i] = ar[low+i];
    }
    for (int j=0; j<n2; j++){
        b[j] = ar[mid+1+j];
    }

    int res = 0, i = 0, j = 0, k = low;
    while(i < n1 && j < n2){
        if (a[i] <= b[j]){
            ar[k] = a[i];    
            i++;
        }
        else {
            ar[k] = b[j++];
            res = res + (n1-i);
        }
        k++;
    }
    while (i < n1){
        ar[k] = a[i];
        i++;
        k++;
    }
    while (j < n2){
        ar[k] = b[j];
        j++;
        k++;
    }
    return res;
}


int print_counts(int ar[], int left, int right){   // TC --> O(N_logN).. AS -> O(N)..
    int re_s = 0;
    if (left < right){
        int mid = left + (right-left)/2;

        re_s += print_counts(ar, left, mid);
        re_s += print_counts(ar, mid+1, right);
        re_s += count_merge(ar, left, mid, right);
    }
    return re_s;
}

int32_t main(){

    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    int left = 0, right = 4;
    // counts(ar, n);

    cout << print_counts(ar, left, right);
    return 0;
}