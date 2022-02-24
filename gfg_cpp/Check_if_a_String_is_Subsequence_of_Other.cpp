/*
    All Subsequences of "abc" are :-

        "", "a", "b", "c", "ab", "ac", "bc", "abc"  -> TOTAL = 8 { 2_power(length of str) }
    
    ** Substring are be in continous order..
    ** Subsequence are be in sequence order with selected items..

    ex: s1 = geeksforgeeks  s2 = grges;

    //      Navie - Solution :- check each and every subsequence, if it match then return true, else false..
                    TC  -> O(2_pow_N * N);
*/
#include<bits/stdc++.h>
#include<string>
using namespace std;

//      Efficient - Solution :-     TC -> O(n+m)  AS -> O(1)    [Using Iteration]
bool sub(string const &str, string const &str1, int n, int m){

    if (n < m){
        return false;
    }
    int j = 0;
    for (int i=0; (i<n && j<m); i++){
        if (str[i] == str1[j]){
            j++;
        }
    }
    return (j == m);
}

//       [Using Recursion]      TC -> O(n+m)    AS -> O(n+m).. for function call set..
bool re(string const &str, string const &str1, int n, int m){
    
    if (m == 0){        // 'm' should check first before 'n'..
        return true;
    }
    else if (n == 0){
        return false;
    }
    if (str[n-1] == str1[m-1]){
        re(str, str1, n-1, m-1);
    }
    else {
        re(str, str1, n-1, m);      //  if not equal items match
    }
}

int32_t main(){
    string str, str1;
    getline(cin, str);
    getline(cin, str1);

    int n, m;
    n = str.length();
    m = str1.length();

    cout << sub(str, str1, n, m) << endl;
    cout << re(str, str1, n, m) << endl;
    
    return 0;
}

