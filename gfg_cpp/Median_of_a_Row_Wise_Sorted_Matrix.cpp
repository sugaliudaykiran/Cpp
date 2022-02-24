/*     Assumptions :- 1) Consider that the Size of matrix is Odd.. 
                      2) Elements that are present in matrix are distinct elements..

        Task to Find the Median :- 1) If the Size is Odd then the Result will be one element..
                                   2) If the Size is Even then the result will be Avg(two elements).. 
*/

#include<bits/stdc++.h>
using namespace std;

const int r = 3, c = 5;         // r*c -> 3*5 --> 15 which is an Odd..

/*                              Navie - Solution :-         TC --> O(R*C log R*C)..
    ** First Put all the element in an axuiliary array[1_D] and Sort them and return the Median element.. **
    ** Efficient Solution :=       Quick Select TC --> O(R*C)..
*/


//        Efficient Solution :=      TC --> O(R * Log(Max - Min)* Log C).. Better than O(R * C)..
                                                       //               {max element} <--|   |--> {Min element}..
// Hint -> Using Binary Search..

const int Max = 100;
                             // Tc --> O(Log(Max *Min) *R *Log(C))..
int M_s(int ar[][Max]){            
// Here the First column will give the least value of Matrix because the elements are sorted in row wise..
// Similar the Last column will provide the highest value of Matrix..
    int mins = ar[0][0], maxs = ar[0][c-1];     // Assuming them and Checking row wise..
    for (int i=1; i<r; i++){
        if (mins > ar[i][0]){
            mins = ar[i][0];        // Finding the Min and Max elements..
        }
        if (maxs < ar[i][c-1]){
            maxs = ar[i][c-1];              // Here it Take TC -> O(R)..
        }
    }

    int med_pos = (r*c + 1)/2;      // Median Position is (Row *Column +1)/2..
    while (mins < maxs){                // Here we are check the Loop only for "Min < Max".. after the Min == Max will stop..
        int mid = (mins + maxs)/2;        // Mid of the Min and Max..
        int mid_pos = 0;                

        for (int i=0; i<r; i++){    // Here upper_bound will provide the next high Iterative Index.. element
            mid_pos += upper_bound(ar[i], ar[i]+c, mid) - ar[i];    //  https://www.geeksforgeeks.org/upper_bound-in-cpp/ ----->  ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
        }

        if (mid_pos < med_pos){
            mins = mid + 1;          // Here alternative way is  max = mid+1.. were as min = mid..
        }
        else {                      // In this case  Mid_pos > Med_pos..
            maxs = mid;          // Here Max will not Mid+1.. because of the [min < max].. we can use the alternative way is max = mid+1.. were as min = mid..
        }
    }
    return mins;         // Here Finally Min and Max will remain same..
}

int32_t main(){
    int M[r][Max];

    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cin >> M[i][j];
        }
    }

    cout << M_s(M);
    

    return 0;
}

/*
ex :=       
        5  10  20  30  40
        1   2  3   4   6 
        11 13  15  17  19

        Med_pos --> (3*5 +1)/2 --> 8..th position is 11..

        1  2  3  4  5  6  10  11  13  15  17  19  20  30  40

*/