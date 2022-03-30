/*
Ceiling on left side in an array    :-
In this we, discusses the problem of accepting an array and for every element of the array,
     one needs to find the Ceiling on Left Side.

    Ex :-       [2, 8, 30, 15, 25, 12]
                -1 -1  -1  30  30  15
    
    ** We can see that on first element "2" we have nothing left of it, "8" has no item is closest greater or equal to "8"..
        "30" has no item closest greater item on left of it, "15" has one item which greater and it's "30" which is left of it,
        "25" has "30" which is closest greater item on left of it.  "12" has "15", "25", "30".. greater item left of it, but 
        "15" is closest item near to "12"..

Try :-
                [30, 20, 10]
                -1   30  20

                [10, 20, 30]
                -1   -1  -1

                [6, 18, 4, 5]
                -1  -1  6  6

    //  Efficient Solution :-   
    
    void print_ceiling(int ar[], int n){
        print(-1);

        (1) create a self - balancing BST (set in c++) let it be s.
        (2) Insert ar[0] into s.
        (3) for (int i=1; i<n; i++){
            if (s contains a ceiling of ar[i]){
                print the ceiling
            }
            else{
                print(-1);
            }
            s.insert(ar[i]);
        }
    }

**    Using hash table takes more time.. which tree has ceiling which is built in..
    ** unordered_set doesn't have lower_bound()..

*/

#include<bits/stdc++.h>
#include<set>
using namespace std;

//      Ceiling on left side :-         TC -> O(n^2)..  AS -> O(1)..
//          Navie Solution :-
void ceils(vector <int> &v, int n){
    cout << -1 << " ";
   
    for (int i=1; i<n; i++){
        int diff = INT_MAX;
        for (int j=0; j<i; j++){
            if (v[j] >= v[i]){
                diff = min(diff, v[j] - v[i]);
            }
        }
        if (diff == INT_MAX){
            cout << -1 << " ";
        }
        else {
            cout << diff + v[i] << " ";
        }
    }
}


//      Efficient Solution :-           TC -> O(n logn)..   AS -> O(1)..
void ceils2(vector <int> &v, int n){
    set <int> s;
    s.insert(v[0]);
    cout << -1 << " ";

    for (int i=1; i<n; i++){
        if (s.lower_bound(v[i]) != s.end()){    //  Here we uses the set to store in a ordered item, 
            cout << *(s.lower_bound(v[i])) << " ";  //  Using lower_bound we get iterator pointing to
        }                                             // item which is equal or next greater else return s.end();
        else{
            cout << "-1" << " ";
        }
        s.insert(v[i]);     //  If present or not we need to insert item to check for next items..
    }
}

int32_t main(){
    
    vector <int> v = {6, 18, 4, 5};     // try :-  {2, 8, 30, 15, 25, 12}

    int n = v.size();

    ceils2(v, n);
    return 0;
}

