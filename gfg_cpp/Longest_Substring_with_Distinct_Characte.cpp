/*

    There are 3 approaches to solve the problem are discussed. O(n^3), O(n^2) and O(n)

    ex :-
        "a b c d"   -> ans = "b c d" which is longest distinct character string..
    

*/
#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<climits>
using namespace std; 

//      Check for Distinct characters.. in string..
bool areDistinct(string &str, int i, int j){    //  O(N)..
    vector <bool> visited(256); 
    for (int k=i; k<j; k++){
        if (visited[str[k]]){
            return false;
        }
        visited[str[k]] = true;
    }return true;
}

//  Navie - Solution :-     check all the possible Substring and match distinct and check it size to be max..
int longDist(string &str){      //  TC -> O(N^3).. AS -> O(1)..
    int res = INT_MIN;
    int n = str.length();

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (areDistinct(str, i, j)){
                res = max(res, (j-i+1));
            }
        }
    }
    return res;
}

//      Efficient - Solution :-     TC -> O(N^2).. AS -> O(1)..
int longDist2(string &str){
    int n = str.length();
    int res = INT_MIN;

    for (int i=0; i<n; i++){
        vector <bool> visited(256);
        for (int j=i; j<n; j++){
            if (visited[str[j]]){
                break;
            }
            else {
                res = max(res, j-i+1);
                visited[str[j]] = true;
            }
        }
    }
    return res;
}

/*     Better Efficient Solution :-  TC -> O(N).. AS -> O(1)..
                a  b  c  a  d  b  d    
    maxEnd(j) : 1  2  3  3  4  4  2

    maxEnd(j) : Length of the longest substring that has distinct characters that ends with "j"

    res = max(from j=0 to n-1) (maxEnd(j))

    Xo, X1, X2,... Xi....Xj-1, Xj, Xn-1
                    |_____|
                        maxEnd(j-1)

    maxEnd(j) can be 2 types..
            1)  maxEnd(j-1) +1       -->   if str[j] is not present in maxEnd(j-1)
            2)  j - prev(str[j]) +1  -->   where prev(str[j]) is previous index of the character str[j]..
                        ^
                        |_> Use for 2 purpose for every update in O(1)..time..

    Ex :-
        prev = [-1, -1, -1,...-1];
        i = 0, res = 0;
        
        0   1   2   3   4   5   6       -> Index..
        a   b   c   a   d   b   d    

        j=0, i=0, maxEnd = 1, res = 1, prev['a'] = 0;
        j=1, i=0, maxEnd = 2, res = 2, prev['b'] = 1;
        j=2, i=0, maxEnd = 3, res = 3, prev['c'] = 2;
        j=3, i=1, maxEnd = 4, res = 3, prev['a'] = 3;
        j=4, i=1, maxEnd = 4, res = 4, prev['d'] = 4;
        j=5, i=2, maxEnd = 4, res = 4, prev['b'] = 5;
        j=6, i=5, maxEnd = 2, res = 4, prev['d'] = 6;

        methods :-  
                    i = max(i, prev[str[j]] +1);
              maxEnd  = j-i+1;
                  res = max(res, max_end);
              prev[str[j]] = j;
*/
//      Best Solution :-
int longDist3(string &str){         // TC -> O(N).. AS -> O(1)..
    int n = str.length();
    int res = INT_MIN, i = 0;
    vector <int> prev(256, -1);     // by direct insert the size and values insted of fill()..
    
    for (int j=0; j<n; j++){
        i = max(i, prev[str[j]] +1);    
        int maxEnd = j-i+1;             // for position of distinct string and it's position..
        res = max(res, maxEnd);         
        prev[str[j]] = j;               // keep the index of itself..
    }
    return res;
}


int32_t main(){
    string str;
    getline(cin, str);

    cout << longDist(str) << endl;
    cout << longDist2(str) << endl;
    cout << longDist3(str) << endl;
    return 0;
}