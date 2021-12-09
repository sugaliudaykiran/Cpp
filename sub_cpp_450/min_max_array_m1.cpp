#include<bits/stdc++.h>
using namespace std;

struct Pair {	// Pair struct is used to return two values from getMinMax();
	int min;
	int max;
}; 

struct Pair getMinMax(int ar[], int n){

	struct Pair minmax;
	int i;

	if (n == 1){
		minmax.max = ar[0];
		minmax.min = ar[0];
		return minmax;
	}

	if (ar[0] > ar[1]){
		minmax.min = ar[1];
		minmax.max = ar[0];
	}
	else {
		minmax.min = ar[0];
		minmax.max = ar[1];
	}

	for (int i=2; i<n; i++){
		if (ar[i] > minmax.max){
			minmax.max = ar[i];
		}
		else if (ar[i] < minmax.min){
			minmax.min = ar[i];
		}
	}
	return minmax;
}


int32_t main(){
	int n;
	cin >> n;
	
	int ar[n];
	 for (int i=0; i<n; i++){
	 	cin >> ar[i];
	}

	struct Pair minmax  = getMinMax(ar, n);

	cout << minmax.min << " " << minmax.max << endl;

	return 0;
}

/*
struct pair getMinMax(int arr[], int n) 
where arr[] is the array of size n whose minimum and maximum are needed. 

METHOD 1 (Simple Linear Search) :-

Initialize values of min and max as minimum and maximum of the first two elements respectively.
Starting from 3rd, compare each element with max and min, and change max and min accordingly 
(i.e., if the element is smaller than min then change min, else if the element is greater than
max then change max, else ignore the element) 

Time Complexity: O(n)

In this method, the total number of comparisons is 1 + 2(n-2)
 in the worst case and 1 + n – 2 in the best case. 
In the above implementation, the worst case occurs when elements are sorted 
 in descending order and the best case occurs when elements are sorted in ascending order.

*/


