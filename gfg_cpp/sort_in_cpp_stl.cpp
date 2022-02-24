// sort() function in C++ STL  implemented in Arrays and Vectors.. and time complexities of the function.
// SORT -> wort case and average case is O(N_log_N)
// And it is uses the Intro sort :-  Hybird of the quick sort and heap sort and Insertion sort..
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

// Used in Struct..
    struct Point{
        int x, y;
    };

    bool mycmp(Point p1, Point p2){
        return p1.y < p2.y;     // we can use based on the conditions as the comparing X or Y values and changing the decrement order by changing the conditions as p1.Y >= p2.y;
    }

int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    sort(ar, ar+n);        

    for (int x : ar)
        cout << x << " ";
    cout << endl;
    
    sort(ar, ar+n, greater <int>());

    for (int y : ar)
        cout << y << " ";
    cout << endl;

    // Vector :-

    vector <int> v = {1, 2, 20, 10};

    sort(v.begin(), v.end());

    for (int z : v){
        cout << z << " ";
    }
    cout << endl;

    sort(v.begin(), v.end(), greater <int>());

    for (int m: v)
        cout << m << " ";
    
    cout << endl;

    // With Object and Ordered..

    Point a[] = {{3,5}, {4,6}, {1,19}};

    n = sizeof(a)/ sizeof(a[0]);

    sort(a, a+n, mycmp);

    for (auto q : a)
        cout << q.x << " " q.y << endl;

    return 0;
}


/*

  =>  Overview of Sorting Algorithm :- {** Must Know **}

    1) Binary Array (or) Two type of Elements :-  Partition of Quick sort (Lomuto, Hoare, Navie)..

    2) Array with three Values :-                 Partition of Quick sort (Lomuto, Hoare, Navie)..

    3) Array with Size "N" and small ranged Values :-  Counting Sort is used if small range K then Space is O(K).. and TC --> O(N+K)..

    4) Array of Size "N" and range is of size of N_square or N_cube or closer :-    Radix Sort if Size is More like N_square.. TC -> O(N).. AS -> O(N)..

    5) Array of "Uniformly Distributed" Data Over a range :-    Bucket Sort..

    6) When Memory writes are costly :-    Cycle Sort {Optimal in Place of Memory Right.. TC -> O(N_square)}and Selection Sort{Min Swaps  TC -> O(N_square)}..

    7) When only Adjacent swaps are allowed :-   Bubble Sort .. -> Cocktail sort which Better and Upgrade to Bubble sort..

    8) when array size is small :-  Insertion sort {Best one }and Selection sort..

    9) when available extra memory is less :-    Shell sort which Doesn't Uses Extra Memory..and Best.. TC --> O(N * LogN_Square)..


    General Purpose Sorting Algorithms :-
        Merge Sort  {It is Stable.. Used Mostly In Linked List.. and Used in case of Extral Sorting.. this is Divided and Conqure.. Used in Parallel Sorting..}
        Heap Sort   {Uses If Quick sort Does Unfair Sorting..}
        Quick Sort  {Best In Average Cases..    this is Divided and Conqure.. Used in Parallel Sorting..}

    Hybrid Algorithm :-     (Used in Librarics..)
        Tim Sort {Used in Python.. Uses Insertion Sort and Merge Sort..}
        Intro Sort {Used in Cpp.. Uses Quick sort and Heap Sort and Insertion Sort}
        Stable sort {Used in Cpp.. Uses Merge Sort.. }
*/