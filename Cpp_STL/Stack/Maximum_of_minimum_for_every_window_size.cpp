/*
    
    *** Ref :- https://www.geeksforgeeks.org/find-the-maximum-of-minimums-for-every-window-size-in-a-given-array/   
    
    Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
Note: Window size varies from 1 to the size of the Array.

Example 1:

Input:
        N = 3
        arr[] = {10,20,30}
        Output: 30 20 10


Explanation: 
        First element in output indicates maximum of minimums of all
            windows of size 1.Minimums of windows of size 1 are {10} , {20} , {30}.
            Maximum of these minimums are 30 and similarly other outputs can be computed
Your Task:
        The task is to complete the function maxOfMin() which takes the array arr[] and its size N as inputs and
            finds the maximum of minimum of every window size and returns an array containing the result. 
*/ 

#include <bits/stdc++.h>
using namespace std;



class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int ar[], int n)
    {
        stack <int> st;
        vector <int> left(n, -1), right(n, n);
        
        for (int i=0; i<n; i++)     //  TC -> O(n).. SC -> O(n)..
        {
            while (!st.empty() && ar[st.top()] >= ar[i])
            {
                st.pop();
            }
            
            if (!st.empty())
            {
                left[i] = st.top();
            }
            st.push(i);
        }
        
        while (!st.empty())
        {
            st.pop();
        }
        
        for (int i=n-1; i>=0; i--)
        {
            while (!st.empty() && ar[st.top()] >= ar[i])
            {
                st.pop();
            }
            
            if (!st.empty())
            {
                right[i] = st.top();
            }
            st.push(i);
        }
        
        vector <int>res(n+1);
        
        for (int i=0; i<n; i++)
        {
            int x = right[i] - left[i]- 1;
            res[x] = max(res[x], ar[i]);
        }
        
        for (int i=n-1; i>=1; i--)
        {
            res[i] = max(res[i] , res[i+1]);
        }

        vector <int> ans(res.begin()+1, res.end());
        return ans;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
