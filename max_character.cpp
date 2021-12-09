#include<bits/stdc++.h>
using namespace std;
                        
int32_t main(){
    // largest word in a sentence
    int n;
    cin >> n;
    cin.ignore();

    char ar[n+1];
    cin.getline(ar, n);     // getline which allows the space as a word...like sentence.
    cin.ignore();           // which clear buffer one or more character.

    int i=0;
    int current_len = 0, max_len = 0;
    int start = 0, max_st = 0;

    while(1){
        if(ar[i] == ' ' || ar[i] == '\0'){
            if (current_len > max_len){
                max_len = current_len;
                max_st = start;
            }current_len = 0;
            start = i+1;
        }

        else
        current_len++;
        if (ar[i] == '\0')
            break;
        i++;
    }
    cout << max_len << endl;

    for (int i=0; i<max_len; i++){          //for the max_len of char
        cout << ar[i+max_st];                 // upto the max_len of character
        
    }
    return 0;
}