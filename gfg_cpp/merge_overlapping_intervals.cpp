// https://www.geeksforgeeks.org/merging-intervals/

/*  Merge Overlapping Intervals  :- 
        For Ex:- {{1,3}, {2,4}, {5,7}, {6, 8}}      ans :- [Non - OverLapping Interval] {{1, 4}, {5, 8}}
            --> {1, 3} has connection_overlap with {2, 4}  => {min, max}..  --> {1, 4}..
            --> {5, 7} has connection_overlap with {6, 8}  => {min, max}..  --> {5, 8}..
            and we can't see any connnect in between {1, 4} and {5, 8}..
    
    Using pairs :-    pair <int> <int> ar[n];   (or)..
    Using Struct :-     
                        struct Interval {
                            int start;
                            int end;
                        };
                        Interval ar[];
    
    How to Check if Two intervals Overlap ?

        i1 = {5, 10}, i2 = {1, 7};  --> represented in form of {A, B}..
        
        way - 1)
            --> Idea to solve.. first finding the Larger of {A th Place..} of Both Pairs..
            --> And the checks that Larger value is Lies in the Opposite/ Another pair  Between {A , B}.. Places..
            --> will Find the { Min(A th Places of Both intervals..), Max(B th Places of Both intervals..)  }
        way - 2)
            --> Idea to solve.. first finding the Smaller of {B th Place..} of Both Pairs..
            --> And the checks that Smaller value is Lies in the Opposite/ Another pair  Between {A , B}.. Places..

    // Navie - solution :-      TC --> O(N_cubie)..

    A) We traverse to All pairs of the array..and Start Checking the First Pair with every other pairs of intervals..
    B) If it other interval Overlaps with it then we merge and delete other interval..
    C) for Checking and merging takes O(N_square..) and For Deleting takes O(N).. overall ---> O(N_cube)..
    
*/
/*
        Using Struct :-     
                        struct Interval {
                            int start;
                            int end;
                        };
                        Interval ar[];

     Efficient Solution :-   TC --> O(N_LogN).. Implementation.. and Works in Linear Time..

        An efficient approach is to first sort the intervals according to the starting time. 
        Once we have the sorted intervals, we can combine all intervals in a linear traversal. 
     
        The idea is, in sorted array of intervals, if interval[i] doesn’t overlap with interval[i-1], 
        then interval[i+1] cannot overlap with interval[i-1]
     
    **  because starting time of interval[i+1] must be greater than or equal to interval[i]. 
         Following is the detailed step by step algorithm. 
 
*/

// Efficient Solution :-   TC --> O(N_LogN).. Implementation.. and Works in Linear Time..

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

struct Interval {   // Interval has start and end..
    int start, end;
};

// Compares two intervals according to their starting time.
// This is needed for sorting the intervals using library
// function std::sort(). See http://goo.gl/iGspV
bool mycmp(Interval a, Interval b){
    return (a.start < b.start);
}

void merge_(Interval ar[], int n){
    sort(ar, ar+n, mycmp);

    int res = 0;    // Follow as the Index of the Array..

    for (int i=1; i<n; i++){
        if (ar[res].end >= ar[i].start){
            ar[res].start = min(ar[res].start, ar[i].start);
            ar[res].end = max(ar[res].end, ar[i].end);
        }
        else{
            res++;
            ar[res] = ar[i];
        }
    }
    for (int i=0; i <= res; i++){
        cout << "[" << ar[i].start << ", " << ar[i].end  << "]" << " ";
    }
}

int32_t main(){

    Interval ar[] = { {5,10}, {3,15}, {18,30}, {2,7} };         // Which is Static Input..
    int n = sizeof(ar)/sizeof(ar[0]);

    merge_(ar, n);
    return 0;
}
