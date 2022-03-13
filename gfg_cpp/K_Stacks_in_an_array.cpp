/*
        K Stacks in an array :-
    The problem of implementation of K Stacks in an array
    
    *** Ref  :-  https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/
    Code Ref :-  https://ide.geeksforgeeks.org/9zXnmDakzh

    Method 1 (Divide the array in slots of size n/k)
        A simple way to implement k stacks is to divide the array in k slots of size n/k each, 
            and fix the slots for different stacks, i.e., use arr[0] to arr[n/k-1] for first stack, 
            and arr[n/k] to arr[2n/k-1] for stack2 where arr[] is the array to be used to implement 
            two stacks and size of array be n.
        The problem with this method is inefficient use of array space. A stack push operation may result 
            in stack overflow even if there is space available in arr[]. For example, say the k is 2 and array size (n) 
            is 6 and we push 3 elements to first and do not push anything to second second stack. When 
            we push 4th element to first, there will be overflow even if we have space for 3 more elements in array.

    Method 2 (A space efficient implementation) :-
        ** Here we need used to store top of each stack so, we use top[].. array.
        ** we use "next array".. for 2 purpose.. stores for the next item of stack/below item of the stack and also find the free slot..
        ** we use "freeTop = 0".. because the whole array is free.. 
                _________________________                       _______________________
    next []    | 1 | 2 | 3 | 4 | 5 | -1 |        ar[] =        |   |   |   |   |   |   |
                -------------------------                      -------------------------

    top []  =  [-1, -1, -1]     assume, if K is 3.. and freeTop = 0.. and cap = 6 

*/  

#include<bits/stdc++.h>
using namespace std;

struct Kstack{
    int *ar, *next, *top;
    int k, freeTop, cap;
    
    Kstack(int k1, int n){
        cap = n;
        k = k1;
        ar = new int [cap];
        next = new int[cap];
        top = new int[k];

        for (int i=0; i<k; i++){
            top[i] = -1;
        }

        for (int i=0; i<cap-1; i++){
            next[i] = i+1;
        }
        ar[cap-1] = -1;

        freeTop = 0;    //  define that array is free to insert initial..
    }
    
    int isEmpty(int sn){
        return (top[sn] == -1);
    }

    int isFull(){
        return (freeTop == -1); 
    }
    /* Data member (x) and constructor (sn) which tells that on which stack it is storing..*/
    void push(int x, int sn){   
        if (isFull()){
            cout << "Stack is Full..{Overflow}" <<endl;
            return;
        }
        int i = freeTop;
        freeTop = next[i];
        next[i] = top[sn];  //  next is used here for next index..
        top[sn] = i;
        ar[i] = x;
    }

    int pop(int sn){ 
        if (isEmpty(sn)){
            cout << "Stack is Empty..{Underflow}" << endl;
            return INT_MIN;
        }
        int i = top[sn];
        top[sn] = next[i];
        next[i] = freeTop;  //  next is used here for previous item..
        freeTop = i;
        return ar[i];
    }


};

int32_t main(){
    int k1 = 3, n = 10;

    Kstack Ks(k1, n);
    Ks.push(10, 0);
    Ks.push(20, 0);
    Ks.push(30, 0);
    Ks.push(40, 1);
    Ks.push(50, 1);

    cout << Ks.pop(0) << endl;
    cout << Ks.pop(1) << endl;
    return 0;
}

