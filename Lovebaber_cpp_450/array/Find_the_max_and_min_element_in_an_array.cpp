#include<bits/stdc++.h>
using namespace std;

struct Pair
{
	int min;
	int max;
};


struct Pair getMinMax3(int *ar, int n)	//	TC -> O(n).. SC -> O(1)..
{
	struct Pair minmax;
	int i;

	if (n % 2 == 0)
	{
		if (ar[0] > ar[1])
		{
			minmax.min = ar[1];
			minmax.max = ar[0];
		}
		else
		{
			minmax.min = ar[0];
			minmax.max = ar[1];	
		}

		i = 2;
	}

	else
	{
		minmax.min = ar[0];
		minmax.max = ar[0];

		i=1;
	}

	while (i < n-1)
	{
		if (ar[i] > ar[i+1])
		{
			if (minmax.min > ar[i+1])
			{
				minmax.min = ar[i+1];
			}

			if (minmax.max < ar[i])
			{
				minmax.max = ar[i];
			}
		}

		else
		{
			if (minmax.min > ar[i])
			{
				minmax.min = ar[i];
			}

			if (minmax.max < ar[i+1])
			{
				minmax.max = ar[i+1];
			}
		}

		i +=2;
	}

	return minmax;
}


struct Pair getMinMax2(int *ar, int low, int high)
{
	struct Pair minmax, lmm, rmm;

	if (high == low)	//		TC -> O(n).. SC -> O(logn).. for function call stack..
	{
		minmax.min = ar[low];
		minmax.max = ar[low];
		return minmax;
	}

	if (high == low+1)
	{
		if (ar[low] > ar[high])
		{
			minmax.max = ar[low];
			minmax.min = ar[high];
		}
		else
		{
			minmax.min = ar[low];
			minmax.max = ar[high];
		}
		return minmax;
	}

	int mid = low + (high - low)/2;

	lmm = getMinMax2(ar, low, mid);
	rmm = getMinMax2(ar, mid, high);

	if (lmm.min < rmm.min)
	{
		minmax.min = lmm.min;
	}
	else
	{
		minmax.min = rmm.min;
	}


	if (rmm.max > lmm.max)
	{
		minmax.max = rmm.max;
	}
	else
	{
		minmax.max = lmm.max;
	}

	return minmax;
}



struct Pair getMinMax(int *ar, int n)		//	TC -> O(n).. SC -> O(1)..
{
	struct Pair minmax;	
	int i;

	if (n == 1)	
	{
		minmax.max = ar[0];
		minmax.min = ar[0];
		return minmax;
	}

	
	if (ar[0] > ar[1])
	{
		minmax.min = ar[1];
		minmax.max = ar[0];
	}
	else
	{
		minmax.min = ar[0];
		minmax.max = ar[1];
	}
	
	for (i=2; i<n; i++)
	{
		if (minmax.min > ar[i])
		{
			minmax.min = ar[i];
		}
		else if (minmax.max < ar[i])
		{
			minmax.max = ar[i];
		}
	}

	return minmax;
}


int32_t main()
{
	int n;
	cin >> n;

	int *ar = new int[n];

	for (int i=0; i<n; i++)
	{
		cin >> ar[i];
	}

	struct Pair x = getMinMax3(ar, n);

	// struct Pair x = getMinMax2(ar, 0, n-1);

	cout << "Min : "<< x.min << ", " <<"Max : "<< x.max << "\n";

	return 0;
}


/*

	In this method, the total number of comparisons is 1 + 2(n-2) in the worst case 
		and 1 + n – 2 in the best case. 
	In the above implementation, the worst case occurs when elements are sorted in descending order
		 and the best case occurs when elements are sorted in ascending order.
----------------------->

	Algorithm paradigm :	Divide and conquer.

		T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2
		T(2) = 1
		t(1) = 0

	If n is power of 2, then we can write T(n) as:
		T(n) = 2T(n/2) + 2
	
	After solving the above recursion, we get 
  		T(n)  = 3n/2 -2
	Thus, the approach does 3n/2 -2 comparisons 

if n is a power of 2. And it does more than 3n/2 -2 comparisons if n is not a power of 2.
----------------------->

	Total number of comparisons: Different for even and odd n, see below: 

       If n is odd:    3*(n-1)/2  
       If n is even:   1 Initial comparison for initializing min and max, 
                           and 3(n-2)/2 comparisons for rest of the elements  
                      =  1 + 3*(n-2)/2 = 3n/2 -2
Second and third approaches make the equal number of comparisons when n is a power of 2. 


*/ 