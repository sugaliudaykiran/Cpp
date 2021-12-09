#include<bits/stdc++.h>
using namespace std;

//Iterative way :
void rev(int ar[], int n){
	int start = 0, end = n-1;
								// Time Complexity : O(n)
	while(start < end){
		int temp = ar[start];
		ar[start] = ar[end];
		ar[end] = temp;
		start++;
		end--;
	}
}

// Recursive Way :
void revs(int ar[], int start, int end){
	if (start >= end)
	return;

	int temp = ar[start];
	ar[start] = ar[end];
	ar[end] = temp;

	revs(ar, start+1, end-1);
}

int32_t main(){
	int n;
	cin >> n;

	int ar[n];

	for (int i=0; i<n; i++){
		cin >> ar[i];
	}

	for (int i=0; i<n; i++){
		cout << ar[i] << " ";
	}cout << endl;

	// rev(ar, n);
	int start = 0, end = n-1;
	revs(ar, start, end);

	cout << "Reversed array is :" << endl;
	for (int i=0; i<n; i++){
		cout << ar[i] << " ";
	}

	return 0;
}

/*	Time Complexity : O(n)
Iterative way :
1) Initialize start and end indexes as start = 0, end = n-1 
2) In a loop, swap arr[start] with arr[end] and change start 
and end as follows : 
start = start +1, end = end – 1

Recursive Way :
1) Initialize start and end indexes as start = 0, end = n-1 
2) Swap arr[start] with arr[end] 
3) Recursively call reverse for rest of the array.
Time Complexity : O(n)
*/

