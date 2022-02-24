/*

    This overview of pattern searching algorithms (Naive, Improved Naive for Distinct, Rabin Karp and KMP, Suffix tree).

    Ref :- https://www.geeksforgeeks.org/algorithms-gq/pattern-searching/

    ex :-
            txt = "geeksforgeeks";
        pattern = "eks";
            o/p =>  2   10     {Indexs}

            txt = "aaaaa";
        pattern = "aaa";
            o/p => 0  1  2      {Indexs}

    ** We used in google search, DNA's search, file search and soon..

    >>  m -> pattern length
        n -> Text length
        l <= m <= n     {constrains}
---------------------------------------------------------------------
                                            [No preprocessing]      |
    Navie : O((n-m+1) *m)                                           |   {check each pattern with rep to text}
                                                                    |
    Navie when all characters of pattern are distinct : O(n)        |   {works on distinct values}
--------------------------------------------------------------------|                                                                
                                            [Preprocess Pattern]    |
                                                                    |
    Rabin Karp : O((n-m+1) *m)  {But Better than Navie on Average}  |   {use hash map.. In wrost case every item is matched..}                                   
                                                                    |                            
    KMP  : O(n)                                                     |   {Most "V.IMP" which is takes linear time and perform LPS array {Longest proper prefix and suffix}}      
                                                                    |   {other z Algorithm is simple than KMP }, {Used in Dynamic purpose..}
--------------------------------------------------------------------|                                                                                                                                    
                                            [Preprocess Text]       |
                                                                    |
    Suffix Tree   : O(n)                                            |   {which works on fixed text and searching and "TRY"}
                                                                    |
---------------------------------------------------------------------                                                                    

*/

#include<bits/stdc++.h>
#include<string>
using namespace std;

//      Navie - Solution :-          TC -> O((n-m+1) *m)    {This Quardatic and more complex..}
void ps(string const &t, string const &p){
    int n = t.length();         //  text length..
    int m = p.length();         //  pattern length..

    for (int i=0; i<=n-m; i++){     //  division of time to check in text..
        int j;                  
        for (j=0; j<m; j++){
            if (p[j] != t[i+j]){    //  check pattern item one by one in text if doesn't match exit..
                break;
            }
        }
        if (j == m){
            cout << i <<" ";      //  matched indexs
        }
    }
}

// Improved  Navie - Solution :-   when all characters of pattern are distinct : O(n)
/*
        ex :- 
            text = "abceabcd"
        pattern  =  "abcd"

    steps -> (1)    "abceabcd"
                    "abcd"
                        ^_  Here it doesn't matched, by pattern is distinct so next character will not match..
                    so, we shift 3 character index to search   

          (2)       "abceabcd"
                       "abcd"   
                        ^_ Here it doesn't matchs at first position so, shift by 1 char index..
                    
          (3)          "abceabcd"
                           "abcd"
                            ^_ It final matchs and return index at 4

    ** In this we modified the Navie, by which pattern are distinct 
*/
void ps2(string const &t, string const &p){     // TC -> 0(N).. AS -> O(1)..    
    int n = t.length();
    int m = p.length();

    for (int i=0; i<= n-m; ){   //  increment based on conditions..
        int j;
        for (j=0; j<m; j++){
            if (p[j] != t[i+j]){    
                break;
            }       //      This is Inner Iteration.. and below conditions will skips iterations..
        }           
        if (j == m){            //  if matchs then print index..
            cout << i << " ";
        }
        
        if (j == 0){        //  if first char is differ then increment "i"
            i++;
        }
        else{              //   if it doesn't match at first and certain index..then update "i"
            i = (i+j);      //  i += j;
        }
    }
}

int32_t main(){
    string t;   //  text
    string p;   //  pattern
    getline(cin, t);
    getline(cin, p);

    // ps(t, p);
    ps2(t, p);
    return 0;
}
