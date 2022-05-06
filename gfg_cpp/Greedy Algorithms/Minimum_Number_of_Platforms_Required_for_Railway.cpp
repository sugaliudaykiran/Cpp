/*

Minimum Number of Platforms Required for a Railway/Bus Station  :-

Ref :- https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
Ref2:- https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station-set-2-map-based-approach/

Given the arrival and departure times of all trains that reach a railway station, the task is to 
    find the minimum number of platforms required for the railway station so that no train waits. 
    We are given two arrays that represent the arrival and departure times of trains that stop.

Examples:  

Input:
       arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00} 
       dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00} 
Output: 3 
Explanation: There are at-most three trains at a time (time between 9:40 to 12:00)

Input: arr[] = {9:00, 9:40} 
       dep[] = {9:10, 12:00} 
Output: 1 
Explanation: Only one platform is needed.

Time Complexity: O(N * log N), One traversal O(n) of both the array is needed after sorting O(N * log N).
Auxiliary space: O(1), As no extra space is required.

*/

#include<bits/stdc++.h>
using namespace std;
  
       int findPlatform(int arr[], int dep[], int n)    //     TC -> O(2n logn) + O(2n)..   SC -> O(1)..
       {
              sort(arr, arr+n);
              sort(dep, dep+n);

              int plat_needed = 1, res = 1;
              int i=1, j=0;        //     i pointing to arr[], j pointing to dep[]..

              while (i<n and j<n)
              {
                     if (arr[i] <= dep[j]){
                            plat_needed++;
                            i++;
                     }
                     else if (arr[i] > dep[j]){
                            plat_needed--;
                            j--;
                     }
                     if (plat_needed > res)
                            res = plat_needed;
              }
              return res;
       }

int32_t main()
{
       int arr[] = { 9775, 494, 252, 1680};
       int dep[] = { 2052, 2254, 1395, 2130};
       int n = sizeof(arr)/sizeof(arr[0]);
       cout << findPlatform(arr, dep, n);

       return 0;

}