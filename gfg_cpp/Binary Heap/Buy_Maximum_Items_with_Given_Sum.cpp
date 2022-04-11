/*

Buy Maximum Items with Given Sum :-    [Purchased Maximum items..]
    In This we, discusses the problem of buying the maximum items with a given sum.

    1) In this, we given cost of n times and a sum.. 
    2) We need find count of items which we can purchased with given sum..
        Ex.,
                cost[] = [1, 12, 5, 111, 200];
                sum = 10
                O/p :-  2

                cost[] = [20, 10, 5, 30, 100];
                sum = 35
                O/p :-  3
    3) We need find out count of maximum items we can purchased from the cost..

    Navie Solution :-           TC -> O(n logn)..
        1) We sort the array and decrement the sum and update the count of items..
        2) In case of Extra space takes O(n)..       

    Efficient Solution :-       TC -> O(n) + O(cnt * logn)..
        1) We change cost to the Min heap and check with sum with top of heap..              creation takes..O(n)..
        2) If top is smaller or equal to sum then we decrement the sum with the top one and pop it..    which takes O(cnt * logn)..
        3) If top is greater then return the cnt..
        4) If not allowed to modify the array then it O(n).. extra spaces..
        
*/ 

#include<bits/stdc++.h>
using namespace std;


int Buy(int cost[], int sum, int n){
    priority_queue <int, vector<int>, greater<int>> pq(cost, cost+n);

    int cnt = 0;
    while (pq.top() <= sum){
        sum = sum - pq.top();
        pq.pop();
        cnt++;
    }
    return cnt;
}

int32_t main(){

    int cost[] = {20, 10, 5, 30, 100};
    int sum = 35;
    int n = sizeof(cost)/sizeof(cost[0]);

    cout << Buy(cost, sum, n) << endl;
    return 0;
}