/*
    ques -> Given an array which has the Values as Low, Mid, High.. 
        and it is sort in form of the index from low to mid (Included).. and Mid+1 to High..
        In some cases the Low can start from any where in the array and ends with the High..
            and make sorted array..
    {Low <= Mid < High..}

    Idea of Implementation :- First we take the N1 from low to Mid , N2 from mid+1 to High..
                        and create the temporary arrays left and right and inserted in the given array..
                        and TC -> 0(N).. and AS -> 0(N)..
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

//                                  TC -> 0(N).. and AS -> 0(N)..
void mg2(int ar[], int n, int low, int mid, int high){
    int n1 = mid - low+1, n2 = high - mid;
                                        // -------->   Setting Up Auxiliary Array :-
    int left[n1], right[n2];

    for (int i=0; i<n1; i++){
        left[i] = ar[low +i];
    }
    for (int j=0; j<n2; j++){
        right[j] = ar[mid +j+1];
    }

                    //  --------------> Standard Merge Logic :-
    int i=0, j=0, k=low;        // K must starts from the low value..
    while (i < n1 && j < n2){
        if (left[i] <= right[j]){
            ar[k] = left[i];    // Or we can use the below syntax..also..
            k++;
            i++;
        }
        else{
            ar[k++] = right[j++];
        }
    }
    while (i < n1){
        ar[k] = left[i];        // Or we can use the below syntax..also..
        k++;
        i++;
    }

    while (j < n2){
        ar[k++] = right[j++];
    }
}

int32_t main(){

    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    int low = 0, mid = 3, high = 8; // Then N is 9..
    
    mg2(ar, n, low, mid, high);
    for (int k : ar){
        cout << k << " ";
    }
    return 0;
}

// 9
// 10 15 20 40 8 11 15 22 25