#include<bits/stdc++.h>
#include<set>
using namespace std;

//      Navie - solution :=     TC --> O(N_square)..
bool zero_s(int a[], int n){
    for (int i=0; i<n; i++){
        int sum = 0;
        for (int j=i; j<n; j++){
            sum += a[j];
            if (sum == 0){
                return true;
            }
        }
    }
    return false;
}

/*          Efficient - Solution :-
        Idea :- Using Prefix - Sum and Hashing 
    
    a0, a1, a2,.. a(i-1), ai, a(i+1)...aj....a(n+1)
    |_________________|   |_____________|
        pre_fix_sum             0                   -->  then total sum = 0;

    if sum of a[i:j] = 0 then pre_sum must be same as total sum..
    
    which means that left half has some sum + zero = total_sum which sum doesn't changed then..
        by inserting pre_fix_sum before checking in it.. if it doesn't find then insert or else return true..
    
    if case of [-3, 2, 1, 4] which result zero then we need to check is any pre_fix sum is equal to zero.. then return true..

*/
bool zr_s(int a[], int n){      //     TC --> O(N)
    unordered_set <int> s;          
    int prefix_sum = 0;

    for (int i=0; i<n; i++){
        prefix_sum += a[i];
        if (s.find(prefix_sum) != s.end()){     // if it already does exists..
            return true;
        }
        else if (prefix_sum == 0){      // checking if prefix_sum is equal to zero..
            return true;
        }

        else {                      // if it doesn't exists then insert..
            s.insert(prefix_sum);
        }
    }
    return false;
}

int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    cout << zero_s(ar, n) << endl;
    cout << zr_s(ar, n) << endl;
    return 0;
}