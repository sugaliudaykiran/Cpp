/*

Sort K-Sorted Array :-
    In this we discusses the problem of how to Sort an array that is already k-sorted.

    1) We are given a K sorted array we need to sort the array..
    2) in this case the array is some what sorted by k elements..
    3) Any element at index i will be present between the indexes i-k to i+k in the sorted array..
        Ex.,     0  1  2   3   4   5   
                [9, 8, 7, 18, 19, 17]       and k = 2;

                 0  1  2  3   4   5 
                [7, 8, 9, 17, 18, 19] in output indexs any element which is changed in between the (index + k) or (index - k) or in it's place..
        
        Ex2.,    0   1  2  3  4   5   6   7    
                [10, 9, 7, 8, 4, 70, 50, 60]    and k = 4;

                 0  1  2  3  4   5   6   7  
                [4, 7, 8, 9, 10, 50, 60, 70] in output indexs can change in btw (i) or (i+k) or (i-k).. positions.. 
    
    
    Navie Solution :-  TC -> O(n logn)..
        1) In this, case we sort the array, which takes O(n logn).
    
    Efficient Solution :-   In-place        TC -> O()
        1) In this we need the elements in increasing order, so we maintain the 
            min heap and an index to insert/update the elements..
        2) By using min heap we know the next element to insert to array..
        3) As per constrain the k elements are sorted in Min heap so we iterates from 0 to k+1..
        4) Then we iterate from k+1 to n and take out the top of Min heap and insert to array..
        3) And with this we insert the items, from k+1 to Min heap parallel..
        4) By the time the we reached the n then, we remove remaining items form the Min heap..
        5) Finally the items are updated in the increasing order..


    Another Approach :-

    priority_queue<int, vector<int>, greater<int>> pq(ar, ar+n);  //  Min Heap..
    while (pq.empty() == false){
        cout << pq.top() << " ";
        pq.pop();
    }cout << endl;

*/     

#include<bits/stdc++.h>
#include<queue>
using namespace std;

void Sort_K_Sorted(int ar[], int k, int n){     //  TC -> O(k logk) Upper bounded..
    priority_queue <int, vector<int>, greater<int>> pq;

    for (int i=0; i<=k; i++){       //  O(k logk)
        pq.push(ar[i]);
    }
    
    int index = 0;
    for (int i=k+1; i<n; i++){      //  (n - k+1) times..
        ar[index++] = pq.top();
        pq.pop();
    }

    while (pq.empty() == false){        //  O(log k)..
        ar[index++] = pq.top();
        pq.pop();
    }
}

int32_t main(){

    int ar[] = {10, 9, 7, 8, 4, 70, 50, 60};
    int n = sizeof(ar)/sizeof(ar[0]);

    int k = 4;

    Sort_K_Sorted(ar, k, n);

    for (int x: ar){
        cout << x << " ";
    }cout << endl;
    return 0;
}