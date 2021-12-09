#include<bits/stdc++.h>
using namespace std;

struct Pair {
    int min;
    int max;
};

struct Pair togetMinMax(int ar[], int n){
    struct Pair minmax;
    int i;

    if (n % 2 == 0){
        if (ar[0] > ar[1]){
            minmax.max = ar[0];
            minmax.min = ar[1];
        }
        else{
            minmax.max = ar[1];
            minmax.min = ar[0];
        }
        i = 2;
    }
    else{
        minmax.min = ar[0];
        minmax.max = ar[0];
        i = 1;
    }
    while (i < n-1){
        if (ar[i] > ar[i+1]){
            if (ar[i] > minmax.max){
                minmax.max = ar[i];
            }
            if (ar[i+1] < minmax.min){
                minmax.min = ar[i+1];
            }
        }
        else{
            if (ar[i+1] > minmax.max){
                minmax.max = ar[i+1];
            }
            if (ar[i] < minmax.min){
                minmax.min = ar[i];
            }
        }
        i += 2;
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

    Pair minmax = togetMinMax(ar, n);
    cout << minmax.min << " " << minmax.max << endl;
    return 0;
}

/*
METHOD 3 (Compare in Pairs) :-

If n is odd then initialize min and max as first element. 
If n is even then initialize min and max as minimum and maximum of the first two elements respectively. 
For rest of the elements, pick them in pairs and compare their 
maximum and minimum with max and min respectively. 

Time Complexity: O(n)

Total number of comparisons: Different for even and odd n, see below: 

       If n is odd:    3*(n-1)/2  
       If n is even:   1 Initial comparison for initializing min and max, 
                           and 3(n-2)/2 comparisons for rest of the elements  
                      =  1 + 3*(n-2)/2 = 3n/2 -2
Second and third approaches make the equal number of comparisons when n is a power of 2. 
In general, method 3 seems to be the best.

*/