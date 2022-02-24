#include<bits/stdc++.h>
#include<string>

using namespace std;

int32_t main(){
    string s = "bfejbkfekbefnfbbefewjk";

    int freq[26];   // because of a-z is 26;

    for (int i=0; i<26; i++){
        freq[i] = 0;
    }

    for (int i=0; i<s.size(); i++){
        freq[s[i] - 'a']++;
        // Here is freq of index 0 -> 'a' and soon..
    }
    char ans = 'a';
    int  MaxFq = 0; // maximum frequency 

    for (int i=0; i<26; i++){
        if (freq[i] > MaxFq){
            MaxFq = freq[i];
            ans = 'a' + i; // a is index at 0;
        }
    }
    cout << MaxFq << " " << ans << endl;
    return 0;
}