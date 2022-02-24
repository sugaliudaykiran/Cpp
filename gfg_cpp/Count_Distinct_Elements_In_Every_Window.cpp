/*
    Given an array, one needs to Count Distinct Elements In Every Window of Size K.
        K which can be less than or equal to N.
        Count of Windows = (N-k+1)
    Ex:-
        a[] = [10, 10, 5, 3, 20, 5]
            k = 4   and n = 6   -> (n-k+1) = (6-4+1) = 3.. count of windows..
            i = 0   -> [10, 10, 5, 3] -> count of distinct = 3
            i = 1   -> [10, 5, 3, 20] -> count of distinct = 4
            i = 2   -> [5, 3, 20, 5]  -> count of distinct = 3

            output :-   3  4  3 
*/

#include<bits/stdc++.h>
#include<map>
using namespace std;

//      Navie - Solution :=         TC -> O((n-k)*k *k)
int cnt(int a[], int n, int k){
    for (int i=0; i<=n-k; i++){
        int c = 0;
        for (int j=0; j<k; j++){
            bool flag = false;
            for (int p=0; p<j; p++){
                if (a[i+j] == a[i+p]){      // using (i+j) we can traverse every window.. 
                    flag = true;            //  using (p)  we can check previous items of "j".. 
                    break;
                }
            }
            if (!flag){
                c++;
            }
        }
        cout << c << " ";
    }
}

/*
        Efficient - Solution :=     TC -> O(N).. AS -> O(K)..

    1) Create a frequency map of first k items..
    2) Print size of the frequency map..
    3) for (int i=k; i<n; i++){
        a) Decrease frequency of ar[i-k]
        b) If the frequency of ar[i-k] becomes, zero then remove it, from the map..
        c) If ar[i] does not exist in the map then insert it, else increase its frequency in the map..
        d) print size of the map..
    }
    
(i)index ->  0   1   2    3   4   5 
    ex:-  ar[10, 20, 10, 10, 30, 40];
          k = 4;
        (1) -> {10, 3}
               {20, 1}
        (2) -> size = 2..
        (3) -> i = 4 => ar[i] = 30
                        ar[i-k] = 10  // here we remove count in frequency.. 
                {10, 2}
                {20, 1}
                {30, 1}     -> size = 3..
            
            i = 5 => ar[i] = 40
                     ar[i-k] = 20  // here we remove count in frequency.. 
                {10, 2}
                {30, 1}
                {40, 1}     -> size = 3..

    OUTPUT ->  2 3 3 

*/

int cnt2(int a[], int n, int k){    // TC -> O(N).. AS-> O(K)..
    unordered_map <int, int> um;

    for (int i=0; i<k; i++){    // freq map upto k 
        um[a[i]] += 1; 
    }

    cout << um.size() << " ";       

    for (int i=k; i<n; i++){  //  for k to n 
        um[a[i-k]] -= 1;      //  decrease the freq count.. but check previous freq..

        if (um[a[i-k]] == 0){   // if count is zero then erase..
            um.erase(a[i-k]);
        }

        um[a[i]] += 1;      // if it new then insert.. or increase the freq count..

        cout << um.size() << " ";
    }
}

int32_t main(){
    int n, k;
    cin >> n >> k; 

    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    cnt(a, n, k);
    cout << endl;

    cnt2(a, n, k);
    return 0;
}