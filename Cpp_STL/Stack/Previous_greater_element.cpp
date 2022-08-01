/*
    Previous greater element :-     Ref :-  https://www.geeksforgeeks.org/previous-greater-element/

Given an array of distinct elements, find previous greater element for every element.
     If previous greater element does not exist, print -1.

Examples: 
        Input : arr[] = {10, 4, 2, 20, 40, 12, 30}
        Output :         -1, 10, 4, -1, -1, 40, 40

        Input : arr[] = {10, 20, 30, 40}
        Output :        -1, -1, -1, -1

        Input : arr[] = {40, 30, 20, 10}
        Output :        -1, 40, 30, 20

*/ 

#include<bits/stdc++.h>
#include<stack>
using namespace std;

void print_prev_greater(int* ar, int n)   //  Naive Solution :- TC -> O(n^2)..
{
    for (int i=0; i<n; i++)
    {
        int j = 0;
        for (j=i-1; j>=0; j--)
        {
            if (ar[j] > ar[i])
            {
                cout << ar[j] << " ";
                break;
            }
        }
        if (j == -1)
        {
            cout << -1 << " ";
        }
    }
}

void print_prev_greater2(int* ar, int n)  //  Efficient Solution :- TC -> O(n).. SC -> O(n)..
{
    stack<int> st; 
    for (int i=0; i<n; i++)
    {
        while (!st.empty() && st.top() <= ar[i])
        {
            st.pop();
        }
        int x = (st.empty()) ? -1: st.top();
        cout << x << " ";
        st.push(ar[i]);
    } 
}

int32_t main()
{
    int n;
    cin >> n;
    int *ar = new int[n];

    for (int i=0; i<n; i++)
    {
        cin >> ar[i];
    }

    print_prev_greater2(ar, n);
    return 0;
}