/*
        Navie - Solution :=    TC -> O(N_square)..  AS -> O(1)..

    1) Consider all possible pairs one by one and check for sum.
        ar[] = [8, 3, 9, 4];
            sum = 13;
        pairs => (8, 3), (8, 9), (8, 4), (3, 9), (3, 4), (9, 4)
        then (9, 4) -> sum is 13 then pair is present..
    2) If we find a pair, return true, else return false..

    *there are n(n-1)/2 pairs..
    
*/
#include<bits/stdc++.h>
#include<set>
using namespace std;
        
        //  Navie - solution :=     TC -> O(N_square)..  AS -> O(1)..
void pairs_(int a[], int n, int sum){
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (a[i]+a[j] == sum){
                cout << "Present.." << endl;
                return;
            }
        }
    }
    cout << "Not Present.." << endl;
}

    /*  Efficient - Solution :=     Using two Pointer Apporach :-    TC --> O(N_logN).. AS -> O(N)..
        1) Sort the array or in case sorted array no-need..
        2) after sorting, use two pointer from begin and end iterate them upto (begin < end)..
        3) if begin + end pointing elements is equals to sum then return true or else false..
    */

   /*   Best - Efficient Solution :=     Using Hashing (unordered_set)
        
        Note := First inserting every thing into a hash table then traversing 
                                through the array doesn't work..
                Now if we traverse and look for (sum - ar[i]) in hash_table, we would return in-correct result.
        
        Idea := 
        ex -> ar = {8, 3, 2, 4}, sum = 6;
                h = {8, 3, 2, 4} 
                ** here we check note after inserting to hash, traversing 
                    from ar[0], doesn't find, ar[1] it gets sum is equal but it is wrong.. 
                    here it does pair(3, 3) with itself so it false the condition..
                The right pair is (2, 4)

            {Steps to follow} :=
        1) find  h(sum - ar[i]) is present in hash_table.
        2) if not present then insert in hash_table.. and check next i th value..
        3) if present in hash_table then return true..
        4) else return false..
   
   */

void ps(int a[], int n, int sum){       // TC -> O(N).. AS -> O(N)..
    unordered_set <int> s;

    for (int i=0; i<n; i++){
        if (s.find(sum-a[i]) != s.end()){
            cout << "Present.." << endl;
            return;
        }
        else{
            s.insert(a[i]);
        }
    }
    cout << "Not present..." << endl;
}

int32_t main(){
    int n, sum;
    cin >> n >> sum;

    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    
    pairs_(a, n, sum);
    ps(a, n, sum);
    return 0;
}