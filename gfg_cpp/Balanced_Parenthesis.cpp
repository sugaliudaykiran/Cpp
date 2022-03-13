/*
    Balanced Parenthesis :-
    Given a string of parenthesis ({, }, (, ), [ and ]), we need to check if this string is balanced or not.

*/ 
#include<bits/stdc++.h>
#include<stack>
#include<string>
using namespace std;

bool matching(char a, char b){              
    return(( a == '(' && b == ')' )||
              (a == '[' && b == ']')||
              (a == '{' && b == '}'));
}
//          Balanced Parenthesis :-         TC -> O(N).. AS -> O(N)..
bool isBalanced(string const &str){
    stack <char> st;
    
    for (int i=0; i< str.length(); i++){        //  we can use for each loop..
        if (str[i] == '(' || str[i] == '[' || str[i] == '{'){
            st.push(str[i]);
        }
        else {
            if (st.empty() == true){   //  Initial value is closing character then it false..
                return false;
            }
            if (matching(st.top(), str[i]) == false){    //  if doesn't matching also false..
                return false;
            }
            else {          //      if match then pop() it ..
                st.pop();
            }
        }
    }return (st.empty() == true);   //  finially the items are pop then empty return true..
}

int32_t main(){         //  We are going to use stack here because of LIFO nature..
    
    string str;
    getline(cin, str);
    
    cout << isBalanced(str) << endl;
    for (char s: str){
        cout << s << " ";
    }
    return 0;
}
