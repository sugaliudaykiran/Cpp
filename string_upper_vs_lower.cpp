#include<bits/stdc++.h>
#include<string>

using namespace std;

int32_t main(){
    string s;
    cin >> s;
    cout << s << endl;

    // cout << 'a' - 'A' << endl;  // -> it is 32 difference..

    // Covert to Upper..
    for (int i=0; i<s.size(); i++){
        if (s[i] >= 'a' && s[i] <= 'z'){
            s[i] -= 32;
        }
    }cout << s << endl;

    // Convert to Lower..
    for (int i=0; i<s.length(); i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            s[i] += 32;
        }
    }cout << s << endl;

    // Another way is using In-built_Function..
    transform(s.begin(), s.end(), s.begin(), ::toupper);  // to upper case;
    cout << s << endl;

    transform(s.begin(), s.end(), s.begin(), ::tolower);   // to lower case;
    cout << s << endl; 
    return 0;

}

// ex -> UdaykIran
/*

output :-
UdaykIran
UDAYKIRAN
udaykiran
UDAYKIRAN
udaykiran

*/