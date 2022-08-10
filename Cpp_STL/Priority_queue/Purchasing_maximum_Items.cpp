/*
    Given an array consisting of the cost of toys. Given an integer K depicting the amount 
        of money available to purchase toys. Write a program to find the maximum number of toys
         one can buy with the amount K. 
    Note: One can buy only 1 quantity of a particular toy.

    Ref :- https://www.geeksforgeeks.org/maximise-the-number-of-toys-that-can-be-purchased-with-amount-k/

    I/p :-  cost[] = {1, 12, 5, 111, 200};
            sum = 10;
    O/p :-  2

    I/p :-  cost[] = {20, 10, 5, 30, 100};
            sum = 35;
    O/p :-  3
*/ 

#include<bits/stdc++.h>
#include<queue>
using namespace std;

//  Navie Solution :-  Using Sorting..
int purchaseMax(int *ar, int n, int sum)    
{
    sort(ar, ar+n);
    int res = 0;     // TC -> O(nlogn)..    SC -> O(n).. In case of modification is allowed.. create an new array.

    for (int i=0; i<n; i++)
    {
        if (sum < ar[i])
        {
            return res;
        }
        sum -= ar[i];
        res++;
    }
}

int purchaseMax2(int *ar, int n, int sum)   //  TC -> O(n + (res * LogN))
{       //  Using Min Heap and comparing the top item with sum.. and updating the sum..
    priority_queue<int, vector<int>, greater<int>>pq(ar, ar+n);    //  Min heap..
    int res = 0;

    while (sum >= 0 && !pq.empty() && pq.top() <= sum)
    {
        sum -= pq.top();
        res++;
        pq.pop();
    }
    return res;
}

int32_t main()
{
    int n, sum;
    cin >> n >> sum;
    int *ar = new int[n];
    
    for (int i=0; i<n; i++)
    {
        cin >> ar[i];
    }

    cout << purchaseMax2(ar, n, sum) << "\n";
    return 0;
}
