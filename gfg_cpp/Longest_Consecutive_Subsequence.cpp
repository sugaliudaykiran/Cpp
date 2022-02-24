/*  Given an array, we need to find the longest subsequence that has consecutive elements. 
        These consecutive elements may appear in any order in the subsequence.

    We need to find the longest subsequence in form of x, x+1, x+2, ..x+i;
            with these elements appearing in any order..    
*/

#include<bits/stdc++.h>
#include<algorithm>
#include<set>
using namespace std;

//      Navie - Solution :-  using sorting..
int lon(int a[], int n){      //    TC --> O(N_logN)..  if in case of extra space is allowed then AS -> O(N)..
    sort(a, a+n);
    int res = 1, cur = 1;
    for (int i=1; i<n; i++){
        if (a[i] == a[i-1]+1){      // Check the current with previous one..
            cur++;
        }
        else if (a[i] != a[i-1]){   // In case same elements like {1,2,3,3,4}..
            res = max(res, cur);    // updating the res.. and cur = 1..
            cur = 1;                
        }
    }
    return max(res, cur);   // finally check in case it missed..
}   

/*        Efficient - Solution :=     
    Hints :-
    1) We first insert all elements in hash table..
    2) then we check with " 2_n " lookups, we find the result..

    Ex :-
    a[] = {1, 3, 9, 2, 8, 2};
    h[] = {1, 3, 9, 2, 8};
        
    i = 1   => check for i-1 in hash table, if it not found then it is starting point..
            then cur = 1.. check for i+1 in hash if it present in hash then..
            check for next i+2 in hash.. and i+3 by increment of curr..
            => if (i+cur) is not found then update res..

    like i = 1 --> cur = 1,
                   cur = 2,
                   cur = 3.. it stop because of next element is not present.. then res = 3
    
    i = 3  -> check i-1, which is present in hash (2).. then check next..
    i = 9  -> check i-1, which is present in hash (8).. then check next..
    i = 2  -> check i-1, which is present in hash (1).. then check next..
    i = 8  -> check i-1, which is not present in hash (7).. then 
                cur = 1 and check for next element that is (i+1) in hash (9).. 
                which is present in hash then (cur++) and check (i+2) in hash which not present..
           -> Finally Check the present res with cur.. and takes maximum length..

--------------------------------------------------------------->
There are always 2_n lookups at most.. if size of hash table is 4 then we do 2(4) -> 8 lookups..
    Ex:-
    1) a[] = {1, 3, 9, 2, 8, 2};   
       hash[] = {1, 3, 9, 2, 8};    size of hash_table is (5) then assuming  lookups is 2*(5)..
             i = 1 --> check for 0, 
                        if not present then check for 2,
                        which is present then check for 3,
                        which is present next 4, which is not present.. { COUNT - 4}
            i = 3 --> check for 2, which is present then NEXT..         { COUNT - 1}
            i = 9 --> check for 8, which is present then NEXT..         { COUNT - 1}
            i = 2 --> check for 1, which is present then NEXT..         { COUNT - 1}
            i = 8 --> check for 7, which is not present and check if 9, 
                                   which is present and check for 10, 
                                   which is not present then STOP..     { COUNT - 3}
        
        >> TOTAl COUNT OF lookups is  4+1+1+1+3 -> 10..
        
        >> How it works ?           "len" is the lenght of Subsequence with the given as first..
            >> For first elements : 2 + (len-1)     
            >> For other elements : 1 

    Try for similiar examples :=
    h = {1, 3, 4, 2}    lookups -> 2*(4) -> 8
    h = {8, 20, 4}      lookups -> 2*(3) -> 6
    h = {2, 4, 8, 3}    lookups -> 2*(4) -> 8..

*/

int ls(int a[], int n){
    unordered_set <int> s(a, a+n);      // TC -> 0(N).. AS -> 0(N)
    int res = 1;

    for (auto i: s){    
        if (s.find(i-1) == s.end()){
            int cur = 1;
            while (s.find(i+cur) != s.end()){
                cur++;
            }
            res = max(res, cur);
        }
    }
    return res;
}

int32_t main(){

    int n;
    cin >> n;
    
    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    
    cout << lon(a, n) << endl;
    cout << ls(a, n) << endl;
    return 0;
}