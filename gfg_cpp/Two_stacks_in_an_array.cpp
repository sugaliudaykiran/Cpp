/*
    Two stacks in an array :-
    The problem of implementation of Two stacks in a single array.
    ** We are given an array, we need to implement two stacks in it..

Codes:
    Method 1(Divide the space in two halves)
        1) one halve for stack1 and other for stack2..
        2) If both stacks are divided into two halves and if one stack1 is full and stack2 is empty and overall the arrays has space to insert..
        3) In those case, we can't insert only in stack1 which leds to overflow.. to over come this space issue..

        CPP: https://ide.geeksforgeeks.org/1RDJxwBooj
    
    Method 2(A "space efficient" implementation)
        1) In this we take pointers/insert on both ends of array..
        2) And initial one as top1 = -1 and top2 = capicity (or) length of array(N)..
        3) If we want to push an item in stack1, we can push in it.. and similiar in stack2 also..
        4) and Increment/Decrement the position as top1++, top2--;
        5) In case of pop we do Decrement/Increment the position as top1--; top2++;
*/ 

#include<bits/stdc++.h>
using namespace std;

struct twoStack{
    int cap;
    int *ar;
    int top1, top2;

    twoStack(int n){
        cap = n;
        top1 = -1;
        top2 = n;
        ar = new int [n];
    }
    
    void push1(int d){
        if (top1 < top2-1){     //  Avoiding the Over load..
            top1++;
            ar[top1] = d;
        }
    }
    void push2(int d){
        if (top1 < top2-1){
            top2--;
            ar[top2] = d;
        }
    }

    int pop1(){
        int res = ar[top1];
        top1--;
        return res;
    }
    int pop2(){
        int res = ar[top2];
        top2++;
        return res;
    }
};

int32_t main(){
    int n = 5;

    twoStack ts(5);
    
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);

    cout << ts.pop1() << endl;
    cout << ts.pop2() << endl;
    
    return 0;
}