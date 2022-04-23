/*

Introduction to Greedy Algorithms   :-
    In this we introduces us to the Greedy Algorithms and its various Applications.

Minimum Coins   :-
        Amount = 52;
        coins[] = {1, 2, 5, 10};
            sort the coins in decreasing order..
        coins[] = {10, 5, 2, 1};
            floor(52/10) = 5
            floor(2/2) = 1
        Total minimum no.of coins = 5 + 1 = 6..

        Ref :- https://www.geeksforgeeks.org/greedy-algorithms/
*/ 

#include<bits/stdc++.h>
#include<cmath>
#include<climits>
using namespace std;

int minCoins(int coins[], int n, int amount)
{
    sort(coins, coins+n);   //  array is sorted in ascending order..
    int res = 0;
    for (int i=n-1; i>=0; i--)      //  we iterator from last to 0 index..
    {
        if (coins[i] <= amount){
            int c = floor(amount/coins[i]);
            amount -= c*coins[i];
            res += c;
        }
        if (amount == 0){
            break;
        }
    }   
    return res;
}

int32_t main(){
    int coins[] = {5, 10, 2, 1};
    int n = 4, amount = 57;

    cout << minCoins(coins, n, amount);
}
