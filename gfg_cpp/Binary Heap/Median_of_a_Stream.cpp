/*

Median of a Stream :-
    In this we discusses, the calculation of a Median of a Stream.

    1) We are given and need to find median of a stream at every point..
    2) Median of sequence is the element median half of smaller half of the elements and greater half of elements..
    3) In case of odd elements the middle one is median..
    4) In case of even, median of middle two elements..
    5)  Ex.,        ar[] = [25,  7, 10,  15,  20]
                   med[] = [ 25, 16, 10, 12.5, 15].. which median at every point..
            
            sequence                            median
               {25}                               25         
               {25, 7}                          (25+7)/2 = 16
               {25, 7, 10}                        10
               {25, 7, 10, 15}                    12.5
               {25, 7, 10, 15, 20}                15

        Ex2.,         ar[] = [20, 10, 30, 7]
                      med[]= [20, 15, 20, 15]

    6) In this we need to sort upto cur_elements then find the median of elements..
                      
Naive Code(Maintaining Sorted Array) :-     
    1) We maintains a temporay array and maintain the array in sorted order..
    2) In this, maintain temp with represtive to cur_item in the sorted order.. and check median..
    3) If size of temp is odd then, we print the median..  temp[size/2]..
    4) If size of temp is even then, we print (temp[size/2] + temp[(size-1)/2])/2..
    5) In this each insertion takes O(n)..time and overall every elements takes O(n^2)..
    6) Time Complexity :-   O(n^2)..

Better Solution(Augmented BST)  :-
    1) We always use BST to maintain the sorted data..
    2) We insert all the items to BST which takes O(h)..
    3) In find the median in O(h).. is quit diffculit that, which is similiar to K_th smallest element..
    4) By Augment the BST which each node we maintain the count that element are smaller that node..
    5) By this we can check the median in O(h)..
    6) Time Complexity :-   O(nh)..     on average O(nlogn)..

Efficient Solution  :-
    1) We maintain two container, the first contains the smaller elements and second contains greater elements..
    2) In case of Odd case we keep extra in the first container (or) extra in the second container..
    3) In this we maintain in the extra element in the first container..
    4) Initial Both are empty..
    5) Ex.,         ar[] = [25, 7, 10, 15, 20]
                           25  16  10  12.5 15

                        Smaller         Greater
            Initial :   []              []                    median
            i = 0   :   [25]            []                      25
            i = 1   :   [7]             [25]                    16  = (7+25)/2
            i = 2   :   [10, 7]         [25]                    10
            i = 3   :   [10, 7]         [15, 25]                12.5  = (10 + 15)/2
            i = 4   :   [15, 10, 7]     [20, 25]                15      
                        "Max Heap"      "Min Heap"


    6) In this case of odd, the maximum of smaller container is the median.. 
                case of even,  median is (maximum of smaller +  minimum of greater)/2 .. average of it..
    7) In this we use Both Max Heap for smaller and Min Heap for greater containers..
    8) Time Complexity :-   O(n log n)..

*/ 

#include<bits/stdc++.h>
#include<queue>
using namespace std;

void Median(int ar[], int n){       // TC -> O(n logn).. Heap is cache friendly..
    priority_queue <int> s;     //  Max heap.. for smaller elements..
    priority_queue <int, vector<int>, greater <int>> g;     // Min Heap..   for greater elements..
    s.push(ar[0]);
    cout << ar[0] << " ";      //  Initial we insert in 's'

    for (int i=1; i<n; i++){    
        int x = ar[i];              //  In this we can't say the item is insert is always newly added item..        
        if (s.size() > g.size()){       // If 's' has extra element than 'g' then we insert in 'g'..  before inserting 
            if (s.top() > x){           //   check the 's' top is greater than x, then change s.top() with x and insert remove item to 'g'..
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else{           //  else insert to 'g'..
                g.push(x);
            }
            cout << (s.top() + g.top())/2.0 << " ";    //  In this case of Even so average of (s.top() + g.top())/2..
        }
        else{           //  In case of same size of both container.. need to insert extra item in 's' container..
            if (x <= s.top()){
                s.push(x);      //  In this we comparing that s.top and insert to s.
            }
            else{
                g.push(x);
                s.push(g.top());    //  If x is greater than s.top() then we pop the g.top and insert to s.. and insert x to g..
                g.pop();
                
            }
            cout << s.top() << " ";    //  In case of Odd we print s.top().. which is greater in the smaller container..
        }
    }
}

int32_t main(){

    int ar[] = {12, 15, 10, 5, 8, 7, 16};
    int n = sizeof(ar)/sizeof(ar[0]);

    Median(ar, n);

    return 0;
}