/*           String :-

    >> sequences of characters
    >> small set of char
    >> contiguous integer values for 'a' to 'z' and 'A' to 'Z' in both ASCII keys and UTF - 16
    >> 'a' -> 97 and 'A' -> 65.. {26 Alphabets are contiguous..}

                C/Cpp                         Java
    char:  ASCII {8 bits}               UTF - 16 {16 bits}      [unicode standard format]
        also supports wchar_t               also supports byte

    ref :-  https://www.geeksforgeeks.org/stdstring-class-in-c/
 
*/

#include<bits/stdc++.h>
#include<string>
using namespace std;
/*
    Example_problem :
         Print Frequencies of character (in sorted order) in a string of lower case alphabets..
        string = "greeksforgreeks";

*/

int32_t main(){
    
    // char x = 'a';
    // cout << (int)x << endl;

    string str;                 //  TC -> O(N)..
    
    getline(cin, str);              //  "geeksforgeeks"

    int count[26] = {0};            
                                                  // index - 0  1  2 ,,,   25
    for (int i=0; i<str.length(); i++){       //  count[] = [0, 0,, ,, ,,,,0];
        count[str[i] - 'a']++;                //         -> [0, 0,,, 4, 1, 2, ,, 2, ,, 1,, 1,, 2,,]
    }                                     //                 e  f  g     k     o   r    s

    for (int i=0; i<26; i++){
        if (count[i] > 0){    // it will added to 'a' as ASCII('a') + 1 -> 'b' similiar for other..
            cout << (char)(i + 'a') << " " << count[i] << " " << (int)(i+'a') << endl;    
        }
    }
    return 0;
}