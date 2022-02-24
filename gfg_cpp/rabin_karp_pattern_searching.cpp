/*
   ***Must Ref :- https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
    
Works :-
    (1) Like navie algorithm, slide the pattern one by one
    (2) Compare hash values of pattern and current text window.
        if hash values matchs then only compare individual characters..
    
    ex :-          0 1 2 3 4 5 6 7 8 9      -> Indexs..
            txt = "a b d a b c b a b c"                     

        pattern = "a b c"
        where m = 3 {length of pattern}, n = 10 {length of pattern} and "check upto n-m+1 on txt" 
        h : Hash value of pattern 
        t : Hash value of current window of text

        assume :    a: 1, b: 2, c: 3, d: 4, e: 5    or (we can use 0 - 25{alp indexs})

        simple hash : "sum of values"
        problem :  "spurious hits"  {which is matchs but items are miss matched order..}

        p = (1+2+3) = 6             

        i = 0 : t = (1+2+4) = 7
        i = 1 : t = (2+4+1) = 7
        i = 2 : t = (4+1+2) = 7
        i = 3 : t = (1+2+3) = 6 {match}
        i = 4 : t = (2+3+2) = 7
        i = 5 : t = (3+2+1) = 6 {spurious hits}
        i = 6 : t = (2+1+2) = 5
        i = 7 : t = (1+2+3) = 6 {match}

        Idea of rabin karp :-   {Using Rolling Hash}
            t_i+1 = t_i + txt[i+m] - txt[i];          where m is length of pattern..
               ^      ^         ^
               |      |         |
compute hash_val of "i+1" using hash_val of "i" by adding last character of "i+1" char and removing the "i" of last char of window..

    This above may cause more spurious hits as permutation of Characters..
    so,
     Using Improved Hash function :-     {Using weighted sum to undividual charaters..}

           // why pow(2) means pattern size is "m = 3" so d_pow(m-1)

     h("abc") = 1*d_pow(2) + 2*d_pow(1) + 3*d_pow(0) => where d = 5 then   1*5_square + 2*5_pow(1) + 3*5_pow(0) = 38 
     h("dab") = 4*d_pow(2) + 1*d_pow(1) + 2*d_pow(0) = 107

    Rolling :-
        t_i+1 = d(t_i - txt[i] * d_pow(m-1)) + txt[i+m]     // m is length of pattern..

** using with index start with i and substract with first char of prev_window and multiplied by d_pow(m-1) and add last character of next window..

    ex :-          0 1 2 3 4 5 6 7 8 9      -> Indexs..
            txt = "a b d a b c b a b c"                   ptp = "a b c"     p = 1*5_pow(2) + 2*5_pow(1) + 2*5_pow(0) = 38 
        
        t0 = 1*5_pow(2) + 2*5_pow(1) + 2*5_pow(0) = 39
        t1 = 5 *(t0 - 1*5_pow(2)) + 1 = 71
        t2 = 5 *(t0 - 2*5_pow(2)) + 2 = 107
        t3 = 5 *(t2 - 4*5_pow(2)) + 3 = 38

    for ex :-   txt = "1 3 2 4 5 6"
                d = 10, m = 4;
                t0 = 1324       we need 3245
                t1 = 324 * 10 + 5  ==>   1324 - 1*10_pow(3) * 10 + 5 => {3245 val of next_window}


    for coding :-           // pattern
        p = pat[0]*d_pow(m-1) + pat[1]*d_pow(m-2)+...   pat[m-1]*d_pow(0)

        which means :-
            p = 0;
            p = p*d + pat[0];   // p = pat[0]
            p = p*d + pat[1];   // pat[0] * d + pat[1]
            p = p*d + pat[2];   // pat[0] * d_square + pat[1]*d + pat[2]..

*/ 

#include<bits/stdc++.h>
#include<string>
using namespace std;

#define d 256
const int q = 101; 
void RBsearch(string const &txt, string const &pat, int n, int m){  //  TC -> O((N-M+1)* M) which is quardatic.. better than navie..{works in larger and multiple pattern}
    //  Compute d_pow(m-1) % q              
    int h = 1;
    for (int i = 1; i<=m-1; i++){
        h = (h*d) % q;
    }

    //  Compute p and t0
    int p = 0, t = 0;
    for (int i=0; i<m; i++){
        p = (p*d + pat[i]) % q;
        t = (t*d + txt[i]) % q;
    }

    //  Check for spurious hits
    for (int i=0; i<= n-m; i++){
        if (p == t){
            bool flag = true;
            for (int j=0; j<m; j++){
                if (txt[i+j] != pat[j]){
                    flag = false;
                    break;
                }
            }
            if (flag){
                cout << i << " ";
            }
            
        }    
        //  Compute ti+1 using ti
        if (i < n-m){
            t = ((d*(t - txt[i]*h)) + txt[i+m]) % q;
        }
        if (t < 0){
            t = t + q;
        }   
    }
}

int32_t main(){
    string txt, pat;
    getline(cin, txt);
    getline(cin, pat);

    int n = txt.length();
    int m = pat.length();

    RBsearch(txt, pat, n, m);
    return 0;
}