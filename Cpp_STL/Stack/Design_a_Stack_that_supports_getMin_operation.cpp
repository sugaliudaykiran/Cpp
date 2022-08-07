/*
    Ref :- https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/

    Question: Design a Data Structure SpecialStack that supports all the stack operations like push(), 
        pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1).
         To impleent SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list etc.

         Example: 
            Consider the following SpecialStack
                16  --> TOP
                15
                29
                19
                18

            When getMin() is called it should return 15, 
            which is the minimum element in the current stack. 

            If we do pop two times on stack, the stack becomes
                    29  --> TOP
                    19
                    18
    When getMin() is called, it should return 18 which is the minimum in the current stack.
*/ 

#include <bits/stdc++.h>
#include<stack>
using namespace std;

stack <int> Ms, As;

void push(int x)    //  Tc -> O(1).. SC -> O(n)..
{
    if (!Ms.empty() && !As.empty())
    {
        Ms.push(x);
        if (As.top() >= Ms.top())
        {
            As.push(x);
        }
    }
    else
    {
        Ms.push(x), As.push(x);
    }
}

void pop()
{
    if (As.top() == Ms.top())
    {
        As.pop();
    }
    Ms.pop();
}

int getMin()
{
    return As.top();
}

int32_t main()
{
    push(5);
    push(4);
    push(3);
    cout << getMin() << " ";
    pop();
    cout << getMin() << " ";

    push(2);
    cout << getMin() << " ";
    return 0;
}
