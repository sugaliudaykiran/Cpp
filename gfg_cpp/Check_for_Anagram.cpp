/*
    Given two strings, we need to check if these strings are Anagram of each other or not.

    Anagram -> both s1, s2 should contain same set of character..
                {one string is premutation of other string}

    Ex -> s1 = "aaacb",  s2 = "cabaa" are anagram..
*/ 

#include<bits/stdc++.h>
#include<string>
using namespace std;

    //      Navie - Solution :-         TC --> O(n_logn).. AS -> O(1)..
bool a_a(string &s1, string &s2){
    if (s1.length() != s2.length()){
        return false;
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return (s1 == s2);
}

//      Efficient - Solution :-     {Standard character count tech..
const int CHAR = 256;               
bool an(string &s1, string &s2){        //  TC --> O(N + CHAR) .. AS -> O(CHAR)..
    if (s1.length() != s2.length()){
        return false;
    }
    int count[CHAR] = {0};

    for (int i=0; i<s1.length(); i++){
            count[s1[i]]++;
            count[s2[i]]--;      
    }

    for (int i=0; i<CHAR; i++){
        if (count[i] != 0){
            return false;
        }
    }
    return true;
}


int32_t main(){
    
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    cout << a_a(s1, s2) << endl;
    cout << an(s1, s2);
    return 0;
}
