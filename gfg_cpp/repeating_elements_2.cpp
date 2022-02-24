/* Repeating Elements Part (2) :-  TC -> O(N) and AS -> O(1) and no change of original array..
    * All element from 1 to max(arr) are present..
    **  [1 <= max(ar) <= N-1]..
# In this we use cyclie by " The first element  of the cycle will always be the repeating element.."
  In this we need to find the first Node of the cycle..using popular Linked list question..

  ar = [1, 3, 2,  4,  6, 5, 7,  3]
Index - 0 |1| 2  |3| |4| 5 |6| |7|      --> Here it passes through by the Indexs of first..element onwards..

  (1) -> (3) -> (4) -> (6) -> (7)          --> And also form the Cycle and on the first meeting one..is solution..
          *^                   |
           |___________________|
ALgo :- In this case range is 1 <= max(ar) <= N-1..

int find(int ar[], int n){
    int slow = ar[0], fast = ar[0];
    do{
        slow = ar[slow];
        fast = ar[ar[fast]];        -> PHASE (I)
    }
    while(slow != fast)

    slow  = ar[0];
    while(slow != fast){
        slow = ar[slow];            -> PHASE (II)
        fast = ar[fast];
    }
    return slow;
}

Working of the Phase (I) :=
    1) fast will enter the cycle fast (or at the same time..)
    2) In every iteration the distance will be increase by the 1..
    3) When cycle is equal to distance they meet.. and slow and fast meet in any point..

Working of the Phase (II) :=
    1) Before first meeting :-
        fast_distance = 2 * (slow_distance)..   m -> meeting point.. 
        m + x + c * i  = 2 * (m + x + c * j)   i -> iteration.....and c -> cycle is followed...before they meet..
        m + x => c * (i - 2j)..

    2)  (m + x) is multiply of the 'c'..
        i -> iteration_of the fast.....and c -> cycle is followed...before they meet..
        j -> iteration_of the slow.....and c -> cycle is followed...before they meet..

*/
#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#include<deque>

using namespace std;

int rep(int ar[], int n){   // ALgo :- In this case range is 0 <= max(ar) <= N-1
    int slow = ar[0], fast = ar[0];

    do {
        slow = ar[slow]+1;
        fast = ar[ar[fast]+1]+1;
    }while (slow != fast);

    slow = ar[0];
    while (slow != fast){
        slow = ar[slow] +1;
        fast = ar[fast] +1;
    }
    return slow -1;
}


int32_t main(){

    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    cout << rep(ar, n);
    return 0;
}

// ex -> arr[] = {1, 3, 2, 4, 6, 5, 7, 3}, n= 8; ans -> 3..
