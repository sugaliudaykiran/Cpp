#include<bits/stdc++.h> 
#include<string>
using namespace std;

void subset(string &str, string emp = "", int i = 0) {  // &str --> Not to copy the original one..
    if (i == (str.size())){     // Upto length of String..
        cout << emp << endl;    // which return entire values..
        return;
    }
    subset(str, emp, i+1);         // For the Empty..Not add Any new Value..
    subset(str, emp + str[i], i+1);    // for the add the values to it..
}

int32_t main(){
    string str;
    cin >> str;

    subset(str);
    return 0;
}