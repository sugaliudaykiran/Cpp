// This problem is an extension of the previously discussed problem of creating a subarray with zero-sum.
//  This problem discusses the creation of similar subarray with a given input sum.

#include<bits/stdc++.h>
#include<set>
using namespace std;
        //  Navie - Solution :=
bool sub(int a[], int n, int sum){          //  TC --> O(N_square).. AS -> O(1)..
    for (int i=0; i<n; i++){
        int curr_sum = 0;
        for (int j=i; j<n; j++){
            curr_sum += a[j];
            if (curr_sum == sum){
                return true;                
            }
        }
    }
    return false;
}               
/*      Efficient - Solution :-  
   
    a0, a1, a2, a3...ai, a(i+1), ...aj, a(n-1)
    |_________________|     |________|              **=> prefix_sum2 = prefix_sum1 + sum;
        prefix_sum1              sum             

    we need to check "Prefix_sum - Sum" exists among prefix_sum in hash table..
    
    example :-
        a[] = {5, 8, 6, 13, 3, -1}      and sum = 22;
        h = {} is empty..
    i=0 -> pre_sum = 5, h = {5}    before inserting to hash check "prefix_sum - sum" is present in hash_table..
    i=1 -> pre_sum = 13, h = {5, 13}    
    i=2 -> pre_sum = 19, h = {5, 13, 19}   checking "prefix_sum - sum"  => 19 - 22 =>  -3 not present in h..
    i=3 -> pre_sum = 32, h = {5, 13, 19, 32}   checking "prefix_sum - sum"  => 32 - 22 => 10 not present..
    i=4 -> pre_sum = 35, h = {5, 13, 19, 32}   checking "prefix_sum - sum"  => 35 - 22 => 13 is present in hash_table.. then return true..
    
*/

bool sub2(int a[], int n, int sum){     // TC -> O(N).. AS -> O(N)..
    unordered_set <int> s;      // or we can explictly insert the 0 in hash_table in corner case..
    int prefix_sum = 0;         

    for (int i=0; i<n; i++){
        prefix_sum += a[i];
        if (prefix_sum == sum){         //  {2, 3, 4, 6} sum = 9 in this case we can't directly below conditions so in this corner case.. 
            return true;
        }
        if (s.find(prefix_sum - sum) != s.end()){
            return true;
        }
        else{
            s.insert(prefix_sum);
        }
    }
    return false;
}

int32_t main(){
    int n, sum;
    cin >> n >> sum;

    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    
    cout << sub2(a, n, sum) << endl;

    return 0;
}
