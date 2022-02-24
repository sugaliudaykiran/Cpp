#include<bits/stdc++.h>
#include<string>
using namespace std;

//    Navie - Solution :- { TC -> 0(N).. AS -> 0(N) } by reversing the given string..
bool rev(string const &str){      // to avoid of copy to orignial..
    string res = str;           

    reverse(res.begin(), res.end());           // similiar as sort..

    return (str == res);
}

//      Efficient - Solution :-    {TC -> O(N).. AS -> O(1)} by two pointer apporach..
bool two(string const &str){        
    int begin = 0;
    int end = str.length() -1;

    while (begin < end){
        if (str[begin] != str[end]){
            return false;
        }
        begin++;
        end--;
    }
    return true;
}



int32_t main(){

    string str;         // string are mutuable..
    getline(cin, str);

    // cout << rev(str) << endl;
    cout << two(str) << endl;
    return 0;
}