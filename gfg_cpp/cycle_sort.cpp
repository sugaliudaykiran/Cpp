/*

    The Cycle Sort algorithm, its working and analyses the time and space complexity  :=

    A) Cycle Sort in Wrost case O(N_square).. Sorting Algorithm..
    B) Does " Minimum memory writes " and can be useful for cases where memory write Costly..
    C) In-Place and Not Stable..
    D) Useful to solve Questions Like " find Minimum Swaps required " to Sort an array..

    Example of Implementation :-    It is an Works Only for Distinct Elements..
     Given Sort is {20, 40, 50, 10, 30};

     1) Fix the first element as Item then check if any element is smaller than Item..
     2) In above Case 10 is lesser than 20.. so then Index of 20 will be at Index 1 place so we swap 20 with 40 and now Item is 40..
     3) Now check any element is lesser than Item {40}.. in this case 10, 20, 30 are smaller than 40 will be Index at 3..
     4) Now Item is 10 then check any item is smaller than 10 then in above case is 0 then we swap on the Index "0"..
     5) So then again the Item is 20 which forms a cycle then and should STOP..

        {10, 20, 50, 40, 30};

    6) Now the Next element and changing the Item.. if the position is sorted position then it swap itself..
    7) Finally we reach the element on 50 then Item will be 50 and Check any element is less than 50 then there are 10, 20, 30, 40..
    8) Then Index will be at 4 and we swap the element..
    9) then Item is now 30 then element less than 30 is 10, 20.. then Index should be at 3.. and after swaping the Item is again 50.. now we will..swap..
    10) Then Values will be {10, 20, 30, 40, 50};


    Tips :-

    Item towards right-side elements are Not sorted.. and Item towards left-side element are sorted..

    Home Work :-

    1) Do for the Repeated Elements.. In array..
    2) Modify the Cycle and which do less swaps..
    
*/


#include<bits/stdc++.h>
using namespace std;

// Elements are distinct..              TC ---> O(N_square..)
void cycle_Sort_Distinct(int ar[], int n){
    for (int cs = 0; cs < n-1; cs++){         // cs -> Current state..
        int item = ar[cs];              // assume that item is current element..
        int pos = cs;

        for (int i = cs+1; i < n; i++){     // Check from the cs+1..
            if (item > ar[i]){          // If the element is smaller than Item then Increment the Pos++ ..
                pos++;
            }
        }
        swap(item, ar[pos]);

        while (pos != cs){          // For Checking the Cycle is formed or Not..
            pos = cs;

            for (int i = cs +1; i < n; i++){
                if (item > ar[i]){
                    pos++;
                }
            }
            swap(item, ar[pos]);
        }
    }
}

int32_t main(){

    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    cycle_Sort_Distinct(ar, n);

    for(int s: ar){
        cout << s << " ";
    }
    return 0;
}
