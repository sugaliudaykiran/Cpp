/* Median of two sorted arrays .. two approaches to solve the problem.  N1 -> sizeof(A) and N2 -> sizeof(B)..
    I - Approache [Navie_Solution] :-  TC ---> O(N1 + N2) * Log(N1 + N2)..
    1) create an temp_arr of size of the (A + B) arrays..
    2) copy elements of A and B arrays to the temp_arr..
    3) " sort_temp_arr "..
    4)  if length of (A+B) is Odd then return the Mid element..
    5) else .. return average of middle two elements..

    II - Approache [Using Binary_search] :-   N1 -> sizeof(A) and N2 -> sizeof(B)..
                                    TC --> O(Log_N1)..
*/

#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#include<deque>

using namespace std;

double median_2(int ar1[], int ar2[], int n1, int n2){      // TC -> O(Log_N1)..
    int begin1 = 0, end1 = n1;
    while (begin1 < end1){
        int i1 = (begin1 + end1)/2;
        int i2 = ((n1 + n2 + 1)/2) - i1;    // if we known the i1 index this is way to find.. i2..

        int min1 = (i1 == n1)? INT_MAX : ar1[i1];       // Right-set..
        int max1 = (i1 == 0)?  INT_MIN : ar1[i1-1];     // Left-set..

        int min2 = (i2 == n2)?  INT_MAX : ar2[i2];      // Right-set..
        int max2 = (i2 == 0)?   INT_MIN : ar2[i2-1];    // left-set..

        if (min1 >= max2 && min2 >= max1){      // Major Condition..
            if ((n1 + n2) % 2 == 0){            // If it is Even..
                return ((double) max(max1, max2) + min(min1, min2)) / 2;
            }
            else{                               // If it is Odd..
                return (double) max(min1,min2);
            }
        }
        else if (min1 > max2){              // If the Min1 > Max2.. then move end to i1-1;[left side..]
            end1 = i1 -1;
        }
        else {                             // If the Min2 > Max1.. then move begin to i1+1;[right side..]
            begin1 = i1 +1;
        }
    }
    return -1;
}

int32_t main(){
    int n1, n2;
    cin >> n1 >> n2;

    int ar1[n1];
    for (int i=0; i<n1; i++){
        cin >> ar1[i];
    }

    int ar2[n2];
    for (int i=0; i<n2; i++){
        cin >> ar2[i];
    }

    cout << median_2(ar1, ar2, n1, n2);

    return 0;
}

// ex -> {10, 20, 30, 40, 50}, n1 = 5, a2[] = {5, 15, 25, 35, 45}, n2 = 5;
		

