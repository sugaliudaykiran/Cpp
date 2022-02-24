/* # Two Pointer Approach

     1) Find pair in unsorted array which gives sum X
        Navie_Solution := iteration of two loops and check the if sum of two elements is equal to given 'K';
        Efficient_Solution := using the hash table which takes the O(1) time for Insertion, Deletion, Searching..
                                and check if ['K' - arr[i] ]=> is present in the  hash table.. or not and add it..

*/

#include<bits/stdc++.h>
using namespace std;
//Que - 1) Find pair in unsorted array which gives sum X

// Navie_Solution :-        TC -> O(N_square)..
bool check(int ar[], int n, int k){
    for (int i=0; i<n; i++){
        for (int j = i+1; j<n; j++){
            if (ar[i] + ar[j] == k){
                return true;
            }
        }
    }
    return false;
}

// Efficient_Solution :-        Using Hash-Map..    TC  --> O(N)..
void check_pairs(int ar[], int n, int k){
    unordered_set <int> s;  // unorder_set <Type> Name --> Hash_map..
    
    for (int i=0; i<n; i++){    
        int temp = k - ar[i];   // taking temp as the [K - ar[i]]..                                    
        if (s.find(temp) != s.end()){      // and check if it is present in hash-map or else will insert.. 
            cout << "Pair with given sum " << k << " is ( " << ar[i] << ", " << temp <<" )" << endl;
        }
        s.insert(ar[i]);    // then inserting to the hash - table..
    }
    cout << -1;
}

/*  # Two Pointer Approach :-   TC --> O(N)..
    Que - 2)  Find pair in sorted array which gives sum X..
*/

bool use_pointer(int ar[], int n, int k){   //  TC --> O(N)..
    int low = 0, high = n-1;
    
    while (low < high){         // Here we taken the left and  right index and started cheking..
        if (ar[low] + ar[high] == k){   // if equal then return..
            return true;
        }
        else if (ar[low] + ar[high] > k){   // if K is less than value then Decrease high..
            high--;
        }
        else{           // if K is greater than value then Increase low..
            low++;
        }
    }
    return false;
}

/*  # Two Pointer Approach :-   TC --> O(N_square)..
    3)  Find triplet(x+y+z) in an array which gives sum X....
    More Ques -> 4) Count pair with the Given Sum..
                 5) Count Triplet with the given Sum..
        VImp  -> 6) Find if there is a triplet A, B, C such that (A_square + B_square) = C_square..
*/

// Navie_Solution :=  TC -> O(N_Cube)..
bool check_triplet(int ar[], int n, int trp){
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            for (int k = j+1; k<n; k++){
                if (ar[i] + ar[j] + ar[k] == trp){
                    return true;
                }
            }
        }
    }
    return false;
}

// Efficient-Solution :- Will depends on sorted or unsorted in case of both best is using below case as two_pointer and using hash table..
bool pointer(int ar[], int start, int end, int k){
    while (start < end){
        if (ar[start] + ar[end] == k){
            return true;
        }
        else if (ar[start] + ar[end] > k){
            end--;
        }
        else{
            start++;
        }
    }
    return false;
}

bool check_pointer(int ar[], int n, int k){ // TC --> O(N_square) and if we use Hashing.. TC --> O(NlogN) + O(N_square) => O(N_square).. 
    for (int i=0; i<n; i++){
        if (pointer(ar, i+1, n-1, k-ar[i])){
            return true;
        }
    }
    return false;
}


int32_t main(){
    int n, k;
    cin >> n >> k;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // int a_size = sizeof(ar) / sizeof(ar[0]);
    // cout << check(ar, n, k);
    // check_pairs(ar, a_size, k);

    // cout << use_pointer(ar, n, k);
    // cout << check_triplet(ar, n, k);
    cout << check_pointer(ar, n, k);
    return 0;
}