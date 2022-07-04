#include<bits/stdc++.h>
using namespace std;


void ReverseArray(int ar[], int start, int end)
{
	while (start < end)		// Using Iteration TC -> O(n).. SC -> O(1)..
	{
		swap(ar[start], ar[end]);
		start++;
		end--;
	}
}

void ReverseArr2(int *ar, int start, int end)
{
	if (start >= end)		//	Using Recursion TC -> O(n).. SC -> O(1)..
	{
		return;
	}
	swap(ar[start], ar[end]);
	ReverseArr2(ar, start+1, end-1);
}

void PrintArr(int ar[], int n)
{
	for (int i=0; i<n; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
}

int32_t main()
{
	int n;
	cin >> n;

	int ar[n];
	for (int i=0; i<n; i++)
	{ 
		cin >> ar[i];
	}

	ReverseArray(ar, 0, n-1);	//	Using iteration..
	PrintArr(ar, n);


	ReverseArray(ar, 0, n-1);	//	Using Recursion..
	PrintArr(ar, n);

	return 0;
}

/*

				Iteration Way :-
1) Initialize start and end indexes as start = 0, end = n-1 
2) In a loop, swap arr[start] with arr[end] and change start and end as follows : 
start = start +1, end = end – 1


				Recursive Way :-
1) Initialize start and end indexes as start = 0, end = n-1 
2) Swap arr[start] with arr[end] 
3) Recursively call reverse for rest of the array.


*/ 