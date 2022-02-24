/* 
    Given a text and a pattern, the task is to find if there is anagram of pattern present in text.

    ex :-
        txt  = "geeksforgeeks"
        pat  = "frog"       // YES

    Here above example we can see the pattern is present in text, which can direct (or) permutation of pattern, in the text..

    ex :- 
        txt = "geeksforgeeks"
        pat = "reek"        // NO
    
    Here "reek" is not present because, any sort of permutation will not appear in text..

*/
#include<bits/stdc++.h>
#include<string>
using namespace std;

//      check for Anagram or not..  ref :-  https://ide.geeksforgeeks.org/YD5hnovkXx
const int CHAR = 256;
bool areAnagram(string &txt, string &pat, int i){
    int count[CHAR] = {0};
    for (int j=0; j<pat.length(); j++){     // check upto pattern length..
        count[pat[j]]++;            //  adding the last item of new pattern..
        count[txt[i+j]]--;          //  removing the first item of previous pattern..
    }
    for (int j=0; j<CHAR; j++){
        if (count[j] != 0){         // check each val and if any less than or equal to "0" return false..
            return false;
        }
    }return true;
}

//      Navie - Solution :=         TC -> O((n-m+1)* m).. AS -> O(CHAR)..
bool isPresent(string &txt, string &pat){
    int n = txt.length();
    int m = pat.length();

    for (int i=0; i<=n-m; i++){
        if (areAnagram(txt, pat, i)){
            return true;
        }
    }
    return false;
}


//      checking  areSame (or) not..
bool areSame(int *CT, int *CP){     //  int CT[], int CP[]
    for (int i=0; i<CHAR; i++){
        if (CT[i] == CP[i]){        
            return true;
        }
    }return false;
}

//      Efficient - Solution :-         // TC -> O(m+(n-m) *CHAR) => O(N).. AS -> O(CHAR) => O(1)..
bool ispresent(string &txt, string &pat){
    int n = txt.length();
    int m = pat.length();

    int CT[CHAR];    //  count of txt..
    int CP[CHAR];    //  count of pat..

    for (int i=0; i<m; i++){        //  traverse upto m
        CT[txt[i]]++;               //  increment txt items and pat items..
        CP[pat[i]]++;
    }

    for (int j=m; j<n; j++){
        if (areSame(CT, CP)){       // if both are same then return true..
            return true;
        }
        CT[txt[j]]++;       
        CT[txt[j - m]]--;       //  CT[txt[j-pat.length()]]--;
    }
    return false;
}

int32_t main(){
    string txt, pat;
    getline(cin, txt);
    getline(cin, pat);

cout << isPresent(txt, pat) << endl;

cout << ispresent(txt, pat) << endl;
    return 0;
}

