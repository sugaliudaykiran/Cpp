/*      Navie - Solution    :-

    check s1 will be s2 in an rotation like clock (or) anti - clock direction..

1)  s1 = "ABCD"  ->  "BCDA"  ->  "CDAB"
    s2 = "CDAB"     //  YES

2)  s1 = "ABAAA"  ->   "BAAAA"
    s2 = "BAAAA"    //  YES

3)  s1 = "ABAB"   ->   "BABA"  ->  "ABAB"
    s2 = "ABBA"     //  NO

    // Check s1 with each rotation with s2, rotation can be clock (or) anti - clock and it takes O(N_square)..
*/

#include<bits/stdc++.h>
#include<string>
using namespace std;

//      Efficient - Solution :-         // TC -> O(N)..     AS -> O(N).. {because of s1 added itself to check..}
bool rot(string const &s1, string const &s2){
    if (s1.length() != s2.length()){    // check size of both strings..
        return false;        
    }
    return ((s1+s1).find(s2) != string :: npos);    //  Here we add itself and if rotation possible then it will appears, else npos {means not found}
}

int32_t main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    cout << rot(s1, s2);
    return 0;
}

