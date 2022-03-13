/*

Generate numbers with given digits  :-
    This discusses the below problem:
        
    Given a number n, print first n number(in increasing order) such that
        all these numbers have digits in set {5, 6}
    
    Ex :-   I/p : 10
            O/p : 5, 6, 55, 56, 65, 66, 555, 556, 565, 566

            I/p : 4
            O/p : 5, 6, 55, 65 

    Navie - Solution :- 
    ** We run a loop from 1 to Infinite.. check the number as it contains the digits are 5 or 6 only
            if it has print it and increment the count and if count reaches to n then stop..

    Note :- If "n" can a be a big number and the result value might 
                not fit in basic data type like long int (or) long long int..

        Using Queue :-      TC -> O(N)..
    1) We create an empty string queue and push the items "5" and "6" initially..
    2) then pop the item one by one and push the item as cur + "5" and cur + "6" to the queue..

    This works like tree :-
                     ""                             //  initial empty string..
            5                  6                    //  5 and 6 in push to queue..
       55      56          65     66                //  remaining the concate string 5 and 6..
    555 556  665 666   655  656  665  666 

*/ 

#include<bits/stdc++.h>
#include<queue>
using namespace std;

void printFirstN(int n){
    queue <string> q;
    q.push("5");
    q.push("6");

    for (int count = 0; count <n; count++){
        string x = q.front();
        cout << x << " ";
        q.pop();
        q.push(x + "5");
        q.push(x + "6");
    }
}

void Print_upto_N(int n){
    queue <string> q;
    q.push("0");
    q.push("1");
    q.push("2");
    q.push("3");
    q.push("4");
    q.push("5");
    q.push("6");
    q.push("7");
    q.push("8");
    q.push("9");
    cout << q.front() << " ";
    q.pop();
    
    for (int i=0; i<n; i++){    
        string x = q.front();
        cout << x << " ";
        q.pop();
        q.push(x + "0");
        q.push(x + "1");
        q.push(x + "2");
        q.push(x + "3");
        q.push(x + "4");
        q.push(x + "5");
        q.push(x + "6");
        q.push(x + "7");
        q.push(x + "8");
        q.push(x + "9");
    }
}

int32_t main(){

    int n = 7;

    printFirstN(n);

    // Print_upto_N(555);
    return 0;
}


