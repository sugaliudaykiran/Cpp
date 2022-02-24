#include<bits/stdc++.h>
#include<string>
using namespace std;

    // ref -> https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

    //  Please  Check Part - 1;

//        Efficient - solution :-       TC --> O(N)..
void fillLps(string str, int *lps){    //  here lps pointing to lps_array first item..
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

void KMP(string &txt, string &pat){     // TC -> O(N)..     AS -> O(M)..
    int n = txt.length();
    int m = pat.length();
    
    int lps[m];
    fillLps(pat, lps);      //  created lps for given pattern..

    int i=0, j=0;
    while(i < n){               // check from 0 to n in text..
        if (txt[i] == pat[j]){
            i++;                // if match then increment both indexs..
            j++;                    
        }                           
        if (j == m){                // if reached end then print index and check for j index..
            cout << (i-j) << " ";
            j = lps[j-1];
        }
        else if (i < n && txt[i] != pat[j]){
            if (j == 0){                    // if it was starting index..
                i++;
            }
            else{            // check for "j" in previous index of j and check in lps and if val does not match then sliding the items on text..
                j = lps[j-1];
            }
        }
    }
}


int32_t main(){
    string txt, pat;
    getline(cin, txt);
    getline(cin, pat);

    KMP(txt, pat);

    return 0;
}

/*
    txt - ababcababaad
    pat - ababa
*/