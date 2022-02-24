/*

Character_Array :-
** Need to know size beforehand.
** Larger size required for operations (concatenate or append).
** No-terminating extra character.

String_Array :- (used by STL -> Standard Template Lirary..)
** No need to know size beforehand.
** Performing operations like concatenation & append is easier.
** Terminated with a special character '\0'.

*/

#include<bits/stdc++.h> // we can declare as #include "bits/stdc++.h" 
#include<string> // for the using String..
#include<algorithm> // for the sorting purpose.. this are Headerfiles.. 
using namespace std;

// int32_t main(){
//     string str;
//     cin >> str;
//     cout << str << endl;;
//     // Declare the different ways of string..
//     string str1 = "Uday_Kiran";
//     cout << str1 << endl;

//     string str2(5, 'O');
//     cout << str2 << endl;

//     return 0;
// }

// int32_t main(){             // for sentence :-
//     string str;
//     getline(cin, str);

//     cout << str << endl;
//     return 0;
// }

// ***** Function in String :- *************
int32_t main(){
    string s1, s2;
    cin >> s1 >> s2;

    s1.append(s2);                  // Append..
    cout << s1 << endl;

    cout << s1+s2 << endl;          // concatenation..

    s1 = s1+s2;
    cout << s1 << endl;             // concate..

    s1.clear();                     // clear..
    cout << s1 << endl;
    
    cout << s2[1] << endl;          // Indexing..

    string s3 = "abc", s4 = "xyz";  // Comparing is Equal..
    cout << s4.compare(s3) << endl;
    string s5 = "abc";
    cout << s3.compare(s5) << endl; // It should be Equal so.. it gives -> 0;

    if(s5.compare(s3) == 0){        // we can write as (! s5.compare(s3)) -> !false -> true;
        cout <<"Both are Equal.." << endl;
    }

    // on line 55 -> s1.clear it is empty and to check it using empty() function;
    cout << s1.empty() << endl;     // it gives '1';
    if (s1.empty()){
        cout << "s1 is empty.."<< endl;
    }

    // Erase :- is used to remove character from the String..

    string s6 = "nincompoop"; 
    cout << s6.erase(3, 3) << endl; // Here the 3 is starting Index and 
                                    // another 3 is count of character to remove from the String..
    s6.erase(5, 2);
    cout << s6 << endl;

    // Find -> is used to check is present in String and its Index..
    cout << s6.find('i') << endl;
    cout << s6.find("in") << endl; // here is check first charcter in string wise..
    
    // Insert -> is used to insert the String or character to Index Position..
    cout << s6 << endl;
    s6.insert(1, "lol");    
    cout << s6 << endl;
    
    // length or size for size of String..
    string s7 = "Uday@513";
    cout << s7.length() << endl;
    cout << s7.size() << endl;

    for (int i=0; i<s7.length(); i++){
        cout << s7[i] << " ";
    }cout << endl;

    // SubString -> (substr) we can create sub_string using it and providing the Indexing..
    string s8 = s7.substr(5,7); 
    cout << s8 << endl;      

    // String to Integer :- Using (stoi) Function..
    int x = stoi(s8);       // it is 513
    cout << x +2 << endl;      // it return 513 + 2 -> 515;

    // Integer to String :- Using (to_string) function..
    // x -> 513 to string converion
    cout << to_string(x) + "2" << endl; // Here it append the string.. -> 5132 *

    // For sorting the String using Header file as algorithm..
    string z = "zffeofbnwoeifa";
    
    sort(z.begin(), z.end());  // sort is used str.begin() is initial iterator and str.end() is an ending value.

    cout << z << endl;  // z is sorted as lexigrapical order..


    return 0;
}
// most function of string is in STL,,
// (used by STL -> Standard Template Lirary..)