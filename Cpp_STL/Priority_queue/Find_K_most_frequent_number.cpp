/*

   Ref :- https://www.geeksforgeeks.org/find-k-numbers-occurrences-given-array/

    Given an array of n numbers and a positive integer k. The problem is to find k numbers with most occurrences, i.e., 
        the top k numbers having the maximum frequency. If two numbers have the same frequency then the larger number should
         be given preference. The numbers should be displayed in decreasing order of their frequencies. 
         It is assumed that the array consists of k numbers with most occurrences.

   I/p :- ar[] = {10, 5, 20, 5, 10, 10, 30};
        k = 2 
    O/p :- 10 5


    Input : 
        arr[] = {7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9},
        k = 4
    Output: 5 11 7 10
        Explanation:     
            Frequency of 5 = 3
            Frequency of 11 = 2
            Frequency of 7 = 2
            Frequency of 10 = 1
            These four have the maximum frequency and
            5 is largest among rest.
*/ 

#include<bits/stdc++.h>
#include<map>
#include<queue>
using namespace std;

bool myCmp(const pair<int,int>p1, const pair<int, int>p2)
{
    if (p1.second == p2.second)     // In this case the smallest item will, come first.. incase of same frequency..item.
    {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

    //  Navie Solution :-   //  TC -> O(N LogN).. 
void printKfrequent(int *ar, int n, int k)
{
    unordered_map<int, int>mp;
    for (int i=0; i<n; i++)
    {
        mp[ar[i]]++;
    }

    vector<pair<int, int>> V(mp.begin(), mp.end());

    sort(V.begin(), V.end(), myCmp);

    for (int i=0; i<k; i++)
    {
        cout << V[i].first << " ";
    }cout << "\n";
}



struct MYcmp    //  In case of priority_queue must use an class/struct..
{
    bool operator() (const pair<int, int> p1, const pair<int, int> p2)
    {
         // if frequencies of two elements are same
        // then the larger number should come first
        if (p1.second == p2.second)
            return p1.first < p2.first;
 
        // insert elements in the priority queue on the basis of
        // decreasing order of frequencies
        return p1.second < p2.second;
    }
};

void printKfrequent2(int *ar, int n, int k)
{
    //  Using Max Heap..        TC -> O(n + K logn)..
    unordered_map<int, int> mp;
    for (int i=0; i<n; i++)
    {
        mp[ar[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, MYcmp> pq(mp.begin(), mp.end());

    for (int i=0; i<k; i++)
    {
        cout << pq.top().first << " ";
        pq.pop();
    }
}


int32_t main()
{
    int n, k;
    cin >> n >> k;    

    int *ar = new int[n];
    for (int i=0; i<n; i++)
    {
        cin >> ar[i];
    }

    printKfrequent(ar, n, k);

    return 0;
}