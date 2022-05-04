/*

    Find maximum meetings in one room :-

There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is the finish time of meeting i. 
The task is to find the maximum number of meetings that can be accommodated in the meeting room. Print all meeting numbers

Examples: 

Input : s[] = {1, 3, 0, 5, 8, 5}, f[] = {2, 4, 6, 7, 9, 9} 
Output : 1 2 4 5 
First meeting [1, 2] 
Second meeting [3, 4] 
Fourth meeting [5, 7] 
Fifth meeting [8, 9]

Input : s[] = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924}, 
f[] = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252 } 
Output : 6 7 1 

Ref :- https://www.geeksforgeeks.org/find-maximum-meetings-in-one-room/

*/

#include<bits/stdc++.h>
using namespace std;

void maxMeetings(int s[], int f[], int n)       //  TC -> O(n logn)..   SC -> O(n)..
{   
    pair <int, int> a[n+1];
    int i;
    for (int i=0; i<n; i++)
    {
        a[i].first = f[i];
        a[i].second = i;
    }

    sort(a, a+n);   // Sorting of meeting according to their finish time.

    int time_limit = a[0].first;    // Time_limit to check whether new meeting can be conducted or not.

    vector <int> m;

    m.push_back(a[0].second + 1);       // Position start from 1 to N..

    for (int i=1; i<n; i++){            // Check for all meeting whether it can be selected or not.
        if (s[a[i].second] > time_limit)
        {
            m.push_back(a[i].second +1);
            time_limit = a[i].first;            // update time_limit..
        }
    }

    for (int i=0; i<m.size(); i++)  
    {
        cout << m[i] << " ";
    }cout << endl;
}


int32_t main()
{
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};

    int n = sizeof(s)/sizeof(s[0]);

    maxMeetings(s, f, n);
}
