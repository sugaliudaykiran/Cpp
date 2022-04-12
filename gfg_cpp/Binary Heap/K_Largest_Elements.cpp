/*

K Largest Elements  :-
    In this we discusses, the problem of calculating the K Largest Elements in an unsorted array

    1) We are given an unsorted array and k we need to find k largest elements from the array.
    Ex.,        ar[] = [5, 15, 10, 20, 8]
                  k  = 2,
                O/p  = 15  20

    Ex2.,       ar[] = [8, 6, 4, 10, 9]
                  k  = 3,
                O/p  = 8  9  10   
    2) In this we doesn't order of the output, just print the k largest elements..
    
    Navie Solution :-   
        1) In this we sort the array and print the last k elements..
        2) TC is O(n logn)..
    
    Better Solution :-      TC -> O(n + K logn)..
        1) Using Max Heap, In this we insert all items to Max Heap..    O(n)..
        2) And return top of Max Heap one by one.. Upto K elements..    O(k logn)..
        3) Over all TC -> O(n + K logn)

    Efficient Solution :-       TC -> O(k + (n-k) logk)..
        1) Using Min Heap, In this we follow below steps.
        2) Bulid a Min Heap of 'first K items',         O(k)
        3) Travers from (k+1)th element.                O((n-k) logk)
            (a) Compare current element with top of heap.. If smaller than top, then ignore it..
            (b) Else remove the top of heap and insert the current element to the Heap..
                {Min heap maintains K largest element at any point..}
        4) Print Contents of Min Heap..                 O(k)

    Time Complexity :- 
        Min Heap        vs          Max Heap
    
    O(k + (n-k) logk)..           O(n + K logn)..

    If K is smaller like 2 or 3 then    Min heap takes O(n).. then Max heap takes O(n + logn)..
    If K is larger like almost n then   Min heap takes O(n + logn).. then Max heap takes O(n + n logn)..

    >> In general Min heap is better than Max heap..
*/ 

#include<bits/stdc++.h>
#include<queue>
using namespace std;

void K_largest(int ar[], int k, int n){    //     TC -> O(k + (n-k) logk)..
    priority_queue <int, vector<int>, greater<int>> pq(ar, ar+k);

    for (int i=k; i<n; i++){
        if (pq.top() < ar[i]){
            pq.pop();
            pq.push(ar[i]);
        }
    }

    while (pq.empty() == false){
        cout << pq.top() << " ";
        pq.pop();
    }cout << endl;
}

int32_t main(){
    int ar[] = {8, 6, 4, 10, 9, 11, 3, 2};
    int k = 3;
    int n = sizeof(ar)/sizeof(ar[0]);

    K_largest(ar, k, n);
}
