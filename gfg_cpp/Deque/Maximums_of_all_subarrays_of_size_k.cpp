/*
        Maximums of all subarrays of size k     :-
    We are given an array and a number k, we need to find maximums of all subarrays of size k.

    Ex :-  ar[] = {10, 8, 5, 12, 15, 7, 6}            k = 3; where k is smaller or equal to N 
            O/p =>  10  12  15  15  15                result upto (N-k+1) subarray length of max elements..

Efficient - Solution :-     TC -> O(N).. and takes 2N traversal..

        ** Idea is use to deque which we insert/delete on both ends..
        ** We can use Doubly Linked list (or) Circular array..
        ** Using Deque we can implement both stack and queue..
    ****  By maintaining the size of deque is K and front of deque will store the max of each traverse..
    ** In these we store the index of items for which we can define that front can change for next items..
    ** Working :-   If deque is empty then insert and an item and for next item check with front of deque..
                        and if item is smaller than front then insert on back of deque and in case of greater..
                        greater item should insert of front of deque..so we remove all items less than the cur_greater from the Pop_front()..
    ** On after the each item.. print the front of deque.. because it is max of deque..

*/

#include<bits/stdc++.h>
#include<deque>
using namespace std;

//          Navie - Solution :-       TC -> O(N^2)..
void printMax(int ar[], int k, int n){
    for (int i=0; i<n-k+1; i++){
        int maxs = ar[i];
        for (int j = i+1; j<i+k; j++){
            if (ar[j] > maxs){
                maxs = ar[j];
            }
        }
        cout << maxs << " ";
    }cout << endl;
}
//      Efficient - Solution :-         TC -> O(N).. 
void printMax2(int ar[], int k, int n){
    deque <int> dq(k);

    for (int i=0; i<k; i++){                    //  Process the size of K
        if (!dq.empty() && ar[dq.back()] <= ar[i]){ //  check from the back of deque with i th item..   if smaller then pop out..  
            dq.pop_back();
        }
        dq.push_back(i);        //  if greater with back of deque upto front..  than push..
    }

    for (int i=k; i<n; i++){                //  Process the K to N..
        cout << ar[dq.front()] << " ";      

        while (!dq.empty() && dq.front() <= i-k){   //  to move the k Index of arr..
            dq.pop_front();                         //  removing the front and moving forward..
        }
        while (!dq.empty() && ar[dq.back()] <= ar[i]){  // similiar we check the item and if smaller than push or pop..
            dq.pop_back();
        }
        dq.push_back(i);         //  else if item is smaller then space in deque then push..
    }
    cout << ar[dq.front()] << " ";
    cout << endl;
}


int32_t main(){
    int k = 3, n = 7;
    int ar[n] = {10, 8, 5, 12, 15, 7, 6};

    printMax2(ar, k, n);
    return 0;
}
