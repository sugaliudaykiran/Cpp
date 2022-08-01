/*
            Ref:- geeksforgeeks.org/the-stock-span-problem/
            
 The stock span problem is a financial problem where we have a series of n daily price quotes for a stock 
    and we need to calculate the span of the stock’s price for all n days. The span Si of the stock’s price on 
    a given day i is defined as the maximum number of consecutive days just before the given day, for which the 
    price of the stock on the current day is less than its price on the given day. 
    
    
    Example:
        Input: N = 7, price[] = [100 80 60 70 60 75 85]
                        Output:  1   1  1  2   1  4  6

Explanation: Traversing the given input span for 100 will be 1, 80 is smaller than 100 so the span is 1, 
                60 is smaller than 80 so the span is 1, 70 is greater than 60 so the span is 2 and so on. Hence the output
                will be 1 1 1 2 1 4 6.

    Input: N = 6, price[] = [10  4  5 90 120 80]
                    Output:   1  1  2  4  5   1

Explanation: Traversing the given input span for 10 will be 1, 4 is smaller than 10 so the span will be 1, 5 is 
                greater than 4 so the span will be 2 and so on. Hence, the output will be 1 1 2 4 5 1.
*/

#include<bits/stdc++.h>
#include<stack>
using namespace std;

void print_stock_span(int* ar, int n)   //  Naive Solution :- TC -> O(n^2)..
{
    for (int i=0; i<n; i++)
    {
        int span = 0;
        for (int j=i; j>= 0; j--)
        {
            if (ar[i] >= ar[j])
            {
                span++;
            }
            else{
                break;
            }
        }
        cout << span << " ";
    }
}

void print_stock_span2(int* ar, int n)  //  Efficient Solution :- TC -> O(n).. SC -> O(n)..
{
    stack<int> st;  //  By using stack.. used for rectant index_item greater than cur_item.. => (cur_index - st.top())..
                        //      in case of stack empty => (cur_Index+1)
    for (int i=0; i<n; i++)
    {
        while (!st.empty() && ar[st.top()] <= ar[i])
        {
            st.pop();
        }
        int span = (st.empty())? i+1: i - st.top();     //  Check the 
        cout << span << " ";
    
        st.push(i);     //  In case of smaller element then push..
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

    print_stock_span(ar, n);
    return 0;
}