/*
       Reverse words in a string :-

       Naive - Solution :-      TC  -> O(N).. AS -> O(N)..
        1) Create an empty stack    [LIFO]
        2) Push words one by one to the stack
        3) Pop words from the stack and append to output..


       Efficient - Solution :-  TC  -> O(N).. AS -> O(1)..
        1) First reverse the Indiviual words..
        2) then reverse the hole string..
        ex :-
            "abc bcd ef"    -> Input string
            "cba dcb fe"    -> step(1)
            "ef bcd abc"    -> step(2)

*/

#include<bits/stdc++.h>
#include<string>
using namespace std;

    //  Efficient - Solution :-     TC  -> O(N).. AS -> O(1)..

void reverses(char str[], int low, int high){  // we can use reverse(str.begin(), str.end()) function here..
    while(low <= high){
        swap(str[low], str[high]);      
        low++;
        high--;
    }
}


void revs(char str[], int n){        //      here we take char array as input..
    int start = 0;
    for (int end=0; end<n; end++){
        if (str[end] == ' '){                    // in-case of '__' double space we can use while condition for it..
            reverses(str, start, end-1);
            start = end+1;
        }
    }reverses(str, start, n-1);     // it would not reverse the last so we reverse the last word..
    reverses(str, 0, n-1);      //  reverse hole string..
}


int32_t main(){
    // string str;      getline(cin, str);      int n = str.length();
    // char str1[n];     strcmp(str1, str.c_str());         //  here it copys the string to char array..
    char str[] = "abc bcd ef"; 
    int n = strlen(str);    

    revs(str, n);
    cout << str << endl;

    return 0;
}

