/*
    Given a string, the task is to find the first character (whose leftmost appearance is first) that repeats.
*/ 

#include<bits/stdc++.h>
#include<string>
#include<climits>
using namespace std;

//      Navie - Solution :-     // returns the index, of repeating character..
int re(string const &s1){
    int n = s1.length();            //  TC -> O(N_square).. AS -> O(1)..

    for(int i=0; i<n; i++){         // check from next of the current char..
        for (int j=i+1; j<n; j++){
            if (s1[i] == s1[j]){
                return (i);
            }
        }
    }return (-1);
}

//      Better - Apporach :-    TC --> O(N)..with two loops.. AS -> O(CHAR)..
const int CHAR = 256;           
int rep(string const &s1){
    int n = s1.length();

    int count[CHAR] = {0};
    for (int i=0; i<n; i++){
        count[s1[i]]++;
    }

    for (int i=0; i<n; i++){
        if (count[s1[i]] > 1){
            return (i);
        }
    }
    return (-1);
}

//      Efficient - Solution :=         TC -> O(N + CHAR) .. AS -> O(CHAR)
int rep_2(string const &s1){
    int res = INT_MAX, n = s1.length();
    int count[CHAR];
    fill(count, count+CHAR, -1);

    for (int i=0; i<n; i++){
        int fi = count[s1[i]];

        if (fi == -1){
            count[s1[i]] = i;
        }
        else{
            res = min(res, fi);
        }
    }
    return (res == INT_MAX ? -1: res);
}

//      Efficient - Solution_(2) :- {iterating from right to left}  
// here we can leftmost rep_char at last..

int rep_3(string const &s1){        
    int n = s1.length();       //   TC -> O(N + CHAR) .. AS -> O(CHAR)
    bool vis[CHAR];             //  visited arr..
    fill(vis, vis+CHAR, false);
    int res = -1;

    for (int i=n-1; i>0; i--){
        if (vis[s1[i]]){
            res = i;
        }
        else {
            vis[s1[i]] = true;
        }
    }
    return res;
}





int32_t main(){
    string s1;
    getline(cin, s1);

    cout << re(s1) << endl;
    cout << rep(s1) << endl;
    cout << rep_2(s1) << endl;
    cout << rep_3(s1) << endl;
    return 0;
}