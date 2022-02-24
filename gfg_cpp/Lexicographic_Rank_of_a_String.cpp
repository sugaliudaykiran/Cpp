/* 
    Given a string, we need to find lexicographic rank of a string

    ex :=
        str = "BAC"
        rank = 3..
    //      Navie - Apporach :-     TC -> O(N* Fact(N))..
        1) sort the given string and arrange them rank wise over, Lexicographic rank
        2) check all possible outcomes with given string and return rank..

    str = "BAC"
                    Rank`s..
        "ABC"   -> 1        
        "ACB"   -> 2
        "BAC"   -> 3
        "BCA"   -> 4
        "CAB"   -> 5
        "CBA"   -> 6

    try for "CBA", "DCBA", "STRING"..

    //  Efficient - Solution :-     TC -> O(N)..
        *** count Lexicographically smallest strings +1
        
    "S T R I N G"       -> "G I N R S T I"  {sorted order}

    On first character :-   {Here we get 4 character lesser than "S" and has possible factorial of |5__ } = 4*|5_
     R _ _ _ _ _
     N _ _ _ _ _
     I _ _ _ _ _
     G _ _ _ _ _

    On second character :-  {Here we get 4 character lesser than "T" and has possible factorial of |4__ } = 4*|4_
     S R _ _ _ _
     S N _ _ _ _
     S I _ _ _ _
     S G _ _ _ _

    On third character :-   {Here we get 3 character lesser than "R" and has possible factorial of |3__ } = 3*|3_
    S T N _ _ _
    S T I _ _ _
    S T G _ _ _

    on fourth character :-  {Here we get 1 character lesser than "I" and has possible factorial of |2__ } = 1*|2_
    S T R G _ _
    
    on fifth character :-   {Here we get 1 character lesser than "N" and has possible factorial of |1__ } = 1*|1_
    S T R I G _

    on sixth character :-   {Here we get 0 character lesser than "N" and has possible factorial of |0__ } = 0*|0_
    S T R I N G

        TOTAL =  4*|5_ + 4*|4_ + 3*|3_ + 1*|2_ + 1*|1_ = 597

        Rank  = TOTAL +1 =>  598    {count Lexicographically smallest strings +1}

*/

#include<bits/stdc++.h>
#include<string>
using namespace std;

//      to use fact :-
int fact(int n){
    //  using recursion :-
    if (n == 0){
        return (1);
    }
    else {
        return (n * fact(n-1));
    }
/*    //  using iteration :-
    int res = 1;
    for (int i=1; i<=n; i++){
        res *= i;
    }
    cout << res << endl;   
*/
}

//      Efficient - Solution :-
const int CHAR = 256;

int lexiRank(string &str){      //  TC -> O(N).. AS -> O(1)..   {Work for Distinct Characters in string..}
    int count[CHAR] = {0};
    int n = str.length();
    int res = 1, mul = fact(n);

    for (int i=0; i<n; i++){         //  inserting val count in count array..
        count[str[i]]++;
    }
    for (int i=1; i<CHAR; i++){             // consecutive counts of values..
        count[i] += count[i-1];
    }
    for (int i=0; i<n-1; i++){
        mul = mul/(n-i);                      // here we decrement the total fact by current value by this we can get fact via with position..
        res += count[str[i]-1] * mul;       // smaller value of that position and multiple of fact of it..
        for (int j=str[i]; j<CHAR; j++){    // here from left to right we decrease the count of current item in count array..
            count[j]--;
        }
    }
    return res;
}

int32_t main(){
    string str;
    getline(cin, str);
    
    cout << lexiRank(str);
    return 0;
}
