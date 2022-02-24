/*
    Given a string, the task is to find the leftmost character that does not repeat.

*/ 

#include<bits/stdc++.h>
#include<string>
using namespace std;

//      Navie - Solution :-         TC -> O(n_square).. AS -> O(1)..
int n_rep(string const &str){
    int n = str.length();

    for (int i=0; i<n; i++){
        bool flag = false;
        for (int j=i+1; j<n; j++){      //  for (int j=0; j<n; j++){ 
            if (str[i] == str[j]){      //      if (i!=j && str[i] == str[j]){flag = true;}} 
                flag = true;
            }
        }
        if (!flag){
            return (i);
        }
    }return(-1);
}

//      Efficient - Solution :-     {Linear and two traversals is required..}
const int CHAR = 256;               //  TC -> O(N + CHAR).. AS -> O(1)..
int n_rep2(string const &str){      //  it doesn't work for "stream" of characters.. only work for known string..{static..}
    int count[CHAR] = {0};
    int n = str.length();

    for (int i=0; i<n; i++){
        count[str[i]]++;
    }

    for (int i=0; i<n; i++){
        if (count[str[i]] == 1){
            return (i);
        }
    }
    return (-1);
}

//      Most - Efficient - Solution :-   {Linear and one traversal}   TC -> O(N + CHAR)..     AS -> O(CHAR)..
int n_rep3(string const &str){      //  in above solution which doesn't work for "stream" of characters.. but it works for stream..{dynamic}
    int count[CHAR];
    fill(count, count+CHAR, -1);
    int n = str.length();

    for (int i=0; i<n; i++){
        if (count[str[i]] == -1){
            count[str[i]] = i;
        }
        else{
            count[str[i]] = -2;
        }
    }
    int res = INT_MAX;
    for (int i=0; i<CHAR; i++){
        if (count[i] >= 0){
            res = min(res, count[i]);       // Here we insert the Index in position of char's index..
        }
    }
    return (res == INT_MAX)? -1: res;
}


int32_t main(){
    string str;
    getline(cin, str);

    cout << n_rep(str) << endl;
    cout << n_rep2(str) << endl;
    cout << n_rep3(str) << endl;
    return 0;
}