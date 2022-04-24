/*

Fractional Knapsack :-
    In this we talks about C++ implementation of Fractional Knapsack problem.

    Ref :-  https://www.geeksforgeeks.org/fractional-knapsack-problem/
    Ref2 :- https://www.geeksforgeeks.org/c-program-for-the-fractional-knapsack-problem/

*/ 

#include<bits/stdc++.h>
#include<climits>
#include<cmath>
using namespace std;

bool Mycmp(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double) a.first / a.second;
    double r2 = (double) b.first / b.second;

    return r1 > r2;
}

double fKnaps(pair<int, int> ar[], int n, int W)    //  TC -> O(n logn)..
{
    double res = 0.0;
    sort(ar, ar+n, Mycmp);

    for (int i=0; i<n; i++)
    {
        if (ar[i].second <= W)
        {
            W -= ar[i].second;
            res += ar[i].first; 
        }
        else 
        {
            res += ar[i].first * ((double) W/ ar[i].second);
            break;      //  After else W becomes 0..
        }
    }
    return res;
}


int32_t main()
{                                //   value weight  
                                //     |    |
    pair <int, int> ar[] = {make_pair(120, 30), make_pair(100, 20), make_pair(60, 10)};

    int n = 3, W = 50;      //  Knapsack capacity = W

    cout << fKnaps(ar, n, W);
    return 0;
}

