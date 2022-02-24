/*      More than n/k Occurences (O(nk) solution)
    
    Follow's Boyer-Moore Majority Voting Algorithm :-

    https://www.geeksforgeeks.org/tag/moores-voting-algorithm/
    https://www.geeksforgeeks.org/majority-element/

    a[] = [30, 10, 20, 20, 20, 10, 40, 30, 30];
        k = 4, n = 9; 
        res = 20  30    {n/k -> 2.5 then 20 and 30 appears more times..}

    let 'res_count' be the no of elements in the result.

    >>  res_count <= (k-1);
    >> assuming that,
                        k * (n/k +1) <= n 
                          n + k <= n      {which is not TRUE..}

    Moore follows :-    phase I - step(1, 2) and phase II - step(3)..

        1) Create an empty map m;
        2) for (int i=0; i<n; i++){
            a) if (m contains a[i]) then
                    m[a[i]]++;
            b) else if m.size() is less than (k-1) then
                    m.put(a[i], 1);
            c) else 
                    Decrease all values in m by one.
                    if values become 0 then remove it..
        }
        3) For all elements in m, print the elements, that actually appear more than n/k times..

index :    0   1   2   3    4   5   6   7   8 
    a[] = [30, 10, 20, 20, 20, 10, 40, 30, 30];
        k = 4, n = 9; 
        res = 20  30    {n/k -> 2.5 then 20 and 30 appears more times..}

    i = 0: m{{30, 1}}                            [step - 2.b]
    i = 1: m{{30, 1}, {10, 1}}                   [step - 2.b]  
    i = 2: m{{30, 1}, {10, 1}, {20, 1}}          [step - 2.b]
    i = 3: m{{30, 1}, {10, 1}, {20, 2}}          [step - 2.a]
    i = 4: m{{30, 1}, {10, 1}, {20, 3}}          [step - 2.a]
    i = 5: m{{30, 1}, {10, 2}, {20, 3}}          [step - 2.a]
    i = 6: m{{30, 0}, {10, 1}, {20, 2}, {40, 1}} ==> m{{10, 1}, {20, 2}}   [step - 3]
    i = 7: m{{10, 1}, {20, 2}, {30, 1}}          [step - 2.b]
    i = 8: m{{10, 1}, {20, 1}, {30, 2}}          [step - 2.a]

    How does the apporach works ?
     Final map :   {{10, 1}, {20, 1}, {30, 2}}

     Rejected - [10, 20, 30, 40]        Selected - [10, 20, 20, 30, 30]

     40 is Rejected itself and three other..     ** 40 will have (n/k) occurences and one occurenece means (k-1) of other elements.. 

     In the rejected set, an element rejects (k-1) distinct other..

*/

#include<bits/stdc++.h>
#include<map>
using namespace std;

int n_by_k(int a[], int n, int k){
    unordered_map <int, int> um;

    for (int i=0; i<n; i++){
        if (um.find(a[i]) != um.end()){     // if element is already present then count++
            um[a[i]]++;
        }
        else if (um.size() < k-1){          // size is free then insert new element..
            um[a[i]] = 1;
        }
        else {
            for (auto e: um){           //  decrease the count and erase if count is zero..
                e.second--;
                if (e.second == 0){
                    um.erase(e.first);
                }
            }
        }
    }

    for (auto x: um){
        int count = 0;
        for (int i=0; i<n; i++){        // checking in array with map_elements..
            if (x.first == a[i]){
                count++;
            }
        }
        if (count > n/k){               // if count is greater than n/k then print..
            cout << x.first << " ";
        }
    }
}

int32_t main(){
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    n_by_k(a, n, k);
    return 0;
}