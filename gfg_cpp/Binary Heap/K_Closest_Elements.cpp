/*

K Closest Elements  :-
    1) We are given array and x and k, we need to find k clostest item of x in array..
        Ex.,    ar[] = [10, 15, 7, 3, 4]
                x = 8, k = 2;
                O/p   =>    7   10          //  Because 7 and 10 difference is minimum.. in the array..

        Ex2.,   ar[] = [100, 80, 10, 5, 70]
                x = 2, k = 3;
                O/p  =>     5  10  70       //  difference is minimum..

Naive Code  :-      TC -> O(n*k)..  AS -> O(n)..
    1) We use an visited array and iterate the given array k times.. 
    2) In each iteration we find the 1 st closest, 2 nd closest,.. and soon..
    3) Using visited we only consider the only not visited and difference is minimum..
    4) By this we get the items of closest items of x..

Efficient Code  :-      TC -> O(n logk)..   //  Which is also known as K smallest elements..
    1) In this we use Max heap, we iterate upto k_th on array and insert to Max Heap as pair of (difference, index)..
    2) Now iterate from k to n and check with top of pair's difference and if diff is larger the cur diff then pop it and insert the cur diff to pq as pair..
    3) when we reaches the n then we have pair of k items and print them out.. with indexs..

        (a) create a max heap pq, (priority queue)
        (b) Insert diff of k element with represet to it's index..
            for (i=0; i<k; i++){
                pq.push({abs(ar[i] - x), i})
            }
        (c) 
            for (int i=k; i<n; i++){
                int dif = abs(ar[i] - x);
                if (pq.top.first > diff){
                    pq.pop();
                    pq.push({diff, i});
                }
            }
    4)  
        while (pq.empty() == false){
            cout << ar[pq.top().second] << endl;
            pq.pop();
        }  
*/

#include<bits/stdc++.h>
#include<queue>
using namespace std;

//      Navie Solution :-       TC -> O(n*k)..  AS -> O(n)..
void printKclosest(int ar[], int x, int k, int n){
    bool visited[n] = {false};

    for (int i=0; i<k; i++){
        int min_dif = INT_MAX;
        int min_dif_idx;

        for (int j=0; j<n; j++){
            if (visited[j] == false && abs(ar[j] - x) <= min_dif){
                min_dif = abs(ar[j] - x);
                min_dif_idx = j;
            }
        }
        cout << ar[min_dif_idx] << " ";
        visited[min_dif_idx] = true;
    }
}


//      Efficient Solution :-       TC -> O(n logk)..
void printKclosest2(int ar[], int x, int k, int n){
    priority_queue <pair<int, int>> pq;
    for (int i=0; i<k; i++){            //  O(k logk)
        pq.push({abs(ar[i] - x), i});
    }

    for (int i=k; i<n; i++){
        int diff = abs(ar[i] - x);      //  O(n-k logk)
        if (pq.top().first > diff){
            pq.pop();
            pq.push({diff, i});
        }
    }
    while (pq.empty() == false){
        cout << ar[pq.top().second] << " ";     //  O(k logk)..
        pq.pop();
    }
}

int32_t main(){
    int ar[] =  {10, 30, 5, 40, 38, 80, 70};
    int n = sizeof(ar)/sizeof(ar[0]);
    int x =35, k =3;

    printKclosest2(ar, x, k, n);
    return 0;
}