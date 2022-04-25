/*

Job Sequencing Problem  :-
Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job takes a single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if only one job can be scheduled at a time.

Examples: 

Input: Four Jobs with following 
deadlines and profits
JobID  Deadline  Profit
  a      4        20   
  b      1        10
  c      1        40  
  d      1        30
Output: Following is maximum 
profit sequence of jobs
        c, a   


Input:  Five Jobs with following
deadlines and profits
JobID   Deadline  Profit
  a       2        100
  b       1        19
  c       2        27
  d       1        25
  e       3        15
Output: Following is maximum 
profit sequence of jobs
        c, a, e

Ref :-  https://www.geeksforgeeks.org/job-sequencing-problem/

The Time Complexity of the above solution is O(n2).
     It can be optimized using Priority Queue(max heap). TC -> O(n logn).. SC -> O(n)..
*/ 

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

struct Job
{
    char id;
    int dead;
    int profit;
};


bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

void printJob(Job ar[], int n)
{
    sort(ar, ar+n, comparison);

    int result[n];
    bool slot[n];

    for (int i=0; i<n; i++)
    {
        slot[i] = false;
    }

    for (int i=0; i<n; i++)
    {       // Find a free slot for this job (Note that we start from the last possible slot)
        for (int j = min(n, ar[i].dead) -1; j>=0; j--)
        {
            if(slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for (int i=0; i<n; i++)
    {
        if(slot[i])
        {
            cout << ar[result[i]].id << " ";
        }
    }cout << endl;
}



int32_t main()
{
    Job ar[] = { {'a', 2, 100},
                 {'b', 1, 19},
                 {'c', 2, 27},
                 {'d', 1, 25},
                 {'e', 3, 15} };

    int n = sizeof(ar)/sizeof(ar[0]);
    printJob(ar, n);
    return 0;
}