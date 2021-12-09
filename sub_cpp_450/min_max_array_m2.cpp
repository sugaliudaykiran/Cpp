#include<bits/stdc++.h>
using namespace std;

struct Pair {	// Pair struct is used to return two values from getMinMax();
	int min;
	int max;
}; 

struct Pair getMaxMin(int ar[], int low, int high){
    struct Pair maxmin, mml, mmr;
    int mid;

    if (low == high){
        maxmin.max = ar[low];
        maxmin.min = ar[high];
        return maxmin;
    }
    if (low + 1 == high){
        if (ar[low] > ar[high]){
            maxmin.max = ar[low];
            maxmin.min = ar[high];
        }
        else{
            maxmin.max = ar[high];
            maxmin.min = ar[low];
        }
        return maxmin;
    }
    mid = low + high / 2;
    mml = getMaxMin(ar, low, mid);
    mmr = getMaxMin(ar, mid+1, high);

    if (mml.max > mmr.max){
        maxmin.max = mml.max;
    }
    else {
        maxmin.max = mmr.max;
    }

    if (mml.min > mmr.min){
        maxmin.min = mmr.min;
    }
    else 
        maxmin.min = mml.min;

    return maxmin;
}

int32_t main(){
	int n;
	cin >> n;
	
	int ar[n];
	 for (int i=0; i<n; i++){
	 	cin >> ar[i];
	}

    struct Pair maxmin = getMaxMin (ar, 0, n-1); // low = 0; high = n-1 (Index's);
    cout << maxmin.min << " " << maxmin.max << endl;
	return 0;
}

/*
struct pair getMinMax(int arr[], int n) 
where arr[] is the array of size n whose minimum and maximum are needed. 

METHOD 2 (Tournament Method) :-
Divide the array into two parts and compare the maximums and minimums of the 
two parts to get the maximum and the minimum of the whole array.

Pair MaxMin(array, array_size)
   if array_size = 1
      return element as both max and min
   else if arry_size = 2
      one comparison to determine max and min
      return that pair
   else    // array_size  > 2 
      recur for max and min of left half
      recur for max and min of right half
      one comparison determines true max of the two candidates
      one comparison determines true min of the two candidates
      return the pair of max and min

    Time Complexity: O(n) 

Total number of comparisons: let the number of comparisons be T(n). 
 T(n) can be written as follows: 
Algorithmic Paradigm: Divide and Conquer 

             
  T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2  
  T(2) = 1
  T(1) = 0
If n is a power of 2, then we can write T(n) as: 

   T(n) = 2T(n/2) + 2
After solving the above recursion, we get 

  T(n)  = 3n/2 -2
Thus, the approach does 3n/2 -2 comparisons 
if n is a power of 2. And it does more than 3n/2 -2 comparisons 
if n is not a power of 2.

*/


