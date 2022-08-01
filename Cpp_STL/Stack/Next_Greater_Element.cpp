/*

    Next Greater Element :-
Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in the array. Elements for which no greater element exist, consider the next greater element as -1. 

Examples: 
    For an array, the rightmost element always has the next greater element as -1.
    For an array that is sorted in decreasing order, all elements have the next greater element as -1.
    For the input array [4, 5, 2, 25], the next greater elements for each element are as follows.
        Element       NGE
        4      -->   5
        5      -->   25
        2      -->   25
        25     -->   -1

d) For the input array [13, 7, 6, 12}, the next greater elements for each element are as follows.  
  Element        NGE
   13      -->    -1
   7       -->     12
   6       -->     12
   12      -->     -1

*/ 

#include<bits/stdc++.h>
#include<stack>
using namespace std;

void print_next_Greater(int* ar, int n)   //  Naive Solution :- TC -> O(n^2)..
{
    for (int i=0; i<n; i++)
    {
        int j;
        for (j=i+1; j<n; j++)
        {
            if (ar[j] > ar[i])
            {
                cout << ar[j] << " ";
                break;
            }
        }
        if (j == n)
        {
            cout << -1 << " ";
        }
    }
}

vector <int> print_next_Greater2(int *ar, int n)  //  Efficient Solution :- TC -> O(n).. SC -> O(n)..
{
    stack<int> st;
    vector <int> res;

    for (int i=n-1; i>=0; i--)  //  Traverse form left to right..
    {
        while (!st.empty() && st.top() <= ar[i])
        {
            st.pop();
        }
        int x = (st.empty())? -1 : st.top();
        res.push_back(x);
        st.push(ar[i]);
    }
    reverse(res.begin(), res.end());
    return res;
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

    // print_next_Greater(ar, n);

    vector <int> res =  print_next_Greater2(ar, n);
    for(int x: res)
    {
        cout << x <<" ";
    }

    return 0;
}