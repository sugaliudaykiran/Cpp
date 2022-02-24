/*  
    // ref -> https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

         KMP Agorithm (Part 1 : Constructing LPS Array) 

    Two methods of LPS (Longest Proper Prefx Suffix) Array are discussed. 
    One method has time complexity O(n^3) and other method is O(n).

    Constructing Longest Proper Prefix, Suffix Array :-
        ex:-
                   str = "a b c d"
        proper prefix  = "", "a", "ab", "abc"   {it should lesser length than str}
                Suffix = "", "d", "cd", "bcd", "abcd"
        THEN, common longest length is "a" -> 1..

                I/p => str = "a  b  a  b  c"
                lps[] =>     [0, 0, 1, 2, 0]

                I/p => str = "a  a  a  a"
                lps[] =>     [0, 1, 2, 3]

                I/p => str = "a  b  c  d"
                lps[] =>     [0, 0, 0, 0]
        try,
            str = "a b a c a b a d"
            str = "a b b a b b"
            str = "a b a b a b"

    //  Navie hits :-
               0  1  2  3  4  5  6  7   -> Indexs..
        str = "a  b  a  b  a  c  a  b"
        
        len = 7     {start from n-1} 
        str[0], str[1]          => Comparing with each other..
        str[1], str[2]
        str[2], str[3]
        str[3], str[4]
        ..
        str[6], str[7]

        len = 6
        str[0], str[2]
        str[1], str[3]
        str[2], str[4]
        str[3], str[5]
        ..
        str[5], str[6]
        ...

        similiar for len = 5, 4,..
*/

#include<bits/stdc++.h>
#include<string>
using namespace std;

//      Navie - Solution :=             TC --> O(N^3)
int longPropPreSuff(string &str, int n){
    for (int len=n-1; len>0; len--){        // Here checks from n-1 to 0 and with conditions..
        bool flag = true;                   
        for (int i=0; i<len; i++){          //  check from 0 to curr_Len, if str[i] != str[n-len +i] return false..
            if (str[i] != str[n-len +i])    
                flag = false;
        }   
        if (flag){          // If true, then length is longest proper prefix and suffix..
            return len;
        }
    }
    return 0;
}

// void fillLps(str, lps[]){
//     for (int i=0; i<str.length(); i++){         // Here we call each character of the string..
//         Lps[i] = longPropPreSuff(&str, i+1);    //  and check the lps
//     }
// }

/*    Efficient - Solution :=
    
Base idea :-
    1)  If len = Lps[i-1] and str[len] and str[i] are same, then Lps[i] = len+1;
        ____________________________________________
    str |   |   |   |    |    |   |   |    |    |  |
        -------------------------------------------- 
          0,  1, .. len-1, len,        i-1,  i
                                        ^
                                        |_ len
    ex:-
        str[] = a  a  a  a
        lps[] = 0  1  2  3

    i = 0: len = 0, lps = 0;
    i = 1: str[i] and str[len] are same lps[i] = 1 and len = len+1  {1};
    i = 2: str[i] and str[len] are same lps[i] = 2 and len = len+1  {2};
    i = 3: str[i] and str[len] are same lps[i] = 3 and len = len+1  {3};

    lps[i] = len+1; {if there match..}

    2) If str[i] and str[len] are not same..
        (a) if len == 0;
                then lps[i] = 0;
        (b) else, we recursively apply lps[] 
                len = lps[len - 1]
            then compare str[i] with str[len]

*** In simple words :-
        Basic Ideas  :-
            (1) if str[i] and str[len] match lps[i] = len+1, and len++;
            (2) if str[i] and str[len] do not match then 
                    (a) if len = 0;
                            lps[i] = 0;
                    (b) else, len = lps[len-1]; //  we now compare with str[i] and str[len]

    ex:-      0   1   2   3   4   5   6   7
        str = a   b   c   b   a   b   c   a                    
         
        lps[0] = 0, len = 0;
        lps[1] = 0, len = 0;    {2.a}
        lps[2] = 0, len = 0;    {2.a}
        lps[3] = 0, len = 0;    {2.a}
        lps[4] = 1, len = 1;    {1}
        lps[5] = 2, len = 2;    {1}
        lps[6] = 3, len = 3;    {1}
                [case 2.b]
        len = lps[len - 1] = lps[2] = 0;
                [case 1]
        lps[0] = 1, len = 1;

*/

//        Efficient - solution :-       TC --> O(N)..
void fillLpss(string str, int *lps){    //  here lps pointing to lps_array..
    int n = str.length();
    int i = 1,  len = 0;
    lps[0]  = 0;
    
    while(i < n){           //      from 1 to n.. why because of 0 is always 0..
        if (str[i] == str[len]){
            len++;
            lps[i] = len;           // if true then updating lps..
            i++;
        }
        else {
            if (len == 0){      // consider that len == 0 means no change..and increment i;
                lps[i] = 0;
                i++;
            }
            else{
                len = lps[len -1];  // in this case may it stop at condition 1 or 2.a
            }
        }
    }
}

/*

        KMP Agorithm (Part 2 : Complete Algorithm)
    Complete KMP algorithm is discussed. This algorithm uses the LPS array.



*/ 



int32_t main(){
    string txt;
    getline(cin, txt);

    int lps[txt.length()];
    fillLpss(txt, lps);

    for (int i=0; i<txt.length(); i++){
        cout << lps[i] << " ";
    }

    return 0;
}