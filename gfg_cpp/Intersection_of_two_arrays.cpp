// Intersection of two arrays :- elements which has distinct elements has a common on both arrays..

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

        /*      Navie - Solution :=
            1)  initialize : res = 0;
            2)  traverse through every element of a[];
                |-> Check if it has not appeared already
                |-> if a new element and also present in b[], do res++;
            3)  return res;
*/
void ins(int a[],int b[], int n, int m){    // TC --> O(N* (N+M)).. AS-> O(1)..
    int res = 0;
    for (int i=0; i<n; i++){        // Check if a[i] is present in a[0... i-1]..
        bool flag = false;
        for (int j=0; j<i; j++){
            if (a[i] == a[j]){
                flag = true;
                break;
            }
        }                   //  If presenet, ignore it..
        if (flag){
            continue;
        }
        for (int k=0; k<m; k++){    //  Otherwise check in b[].. if present, do res++ ..
            if (a[i] == b[k]){
                res++;
                break;
            }
        }
    }
    cout << res << endl;
}

/*           Efficient - Solution :=    Uses unordered_set, using hashing.. 
        1) insert all elements of a[] in a set "s_a" = {}   0(N)
        2) insert all elements of b[] in a set "s_b" = {}   0(M)
        3) Now traverse through s_a and increment the "res" for elements that are present in s_b .. O(N)
    **  TC -> 0(N+M)... AS -> O(N+M)..

            Efficient - Solution_2 :=       TC --> 0(N+M)..     AS -> 0(N)..
        
        1)  insert all elements of a[] in a set "s_a" = {}      0(N)
        2)  Traverse through b[].. search for every element b[i] in s_a..   0(M)
        3)  if present : 
                |->  Increment res;             O(1)
                |->  Remove b[i] from s_a..     O(1)     
        
        ex :-   a = {10, 20, 10, 30, 20}
                b = {20, 10, 10, 40}
            s_a = {10, 20, 30} we check in b and increment the res and delete the b[i] th element from s_a..

*/  
void ins_2(int a[], int b[], int n, int m){     // TC --> 0(N+M)..     AS -> 0(N)..
/*  int res = 0;
    unordered_set <int> us_a;
    for (int i=0; i<n; i++){
        us_a.insert(a[i]);
    }

    for (int j=0; j<m; j++){
        if (us_a.count(b[j])){
            res++;
            us_a.erase(b[j]);
        }
    }
*/
    int res = 0;
    unordered_set <int> us(a, a+n);     // here we directly converted set using constructor..
    for (int i=0; i<m; i++){
        if (us.find(b[i]) != us.end()){     // checking each element of b[] with set..upto ".end()"..
            res++;
            us.erase(b[i]);
        }
    }
    cout << res << endl;
}

int32_t main(){

    int n, m;
    cin >> n >> m;

    int ar1[n];
    int ar2[m];


    for (int i=0; i<n; i++){
        cin >> ar1[i];
    }

    for (int j=0; j<m; j++){
        cin >> ar2[j];
    }

    ins(ar1, ar2, n, m);
    ins_2(ar1, ar2, n, m);
    return 0;
}