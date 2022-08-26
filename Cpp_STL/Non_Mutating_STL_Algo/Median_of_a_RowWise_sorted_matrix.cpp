// ref :- https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/#:~:text=Simple%20Method%3A%20The%20simplest%20method,O(r*c)

#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;
                            // TC -> O(R* logC) 
// Using Binary Search && a number to 'be median' there should be exactly (n/2) numbers which are less than this number..
int binarySearch(int mat[][MAX], int row, int col)
{
    int min = INT_MAX;
    int max = INT_MIN;

    for (int i=0; i<row; i++) // O(R)
    {
        if (mat[i][0] < min)
        {
            min = mat[i][0];
        }
        if (mat[i][col-1] > max)
        {
            max = mat[i][col-1];
        }
    }

    int desired = (row * col +1)/2; 

    while (min < max) 
    {
        int mid = min + (max - min)/2;
        int place = 0;

        for (int i=0; i<row; i++) // O(R* logC)
        {
            place += upper_bound(mat[i], mat[i]+col, mid) - mat[i];
        }

        if (place < desired)
        {
            min = mid+1;
        }
        else{
            max = mid;
        }
    }
    return min;
}


int32_t main()
{
    int row = 3, col = 3; // Odd sized matrix..

    int mat[][MAX] = {{1, 3, 5}, {2, 6, 9}, {3,6, 9}};

    cout << "Median :" << binarySearch(mat, row, col) << " ";
    return 0;
}