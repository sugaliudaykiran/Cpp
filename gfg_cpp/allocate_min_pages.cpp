/* Allocate Minimum Pages (Naive Method) --> Allocate Minimum number of Pages :=

* Minimize the maximum of the pages allocation..
* Only contiguous pages can be allocated..

// Navie - Recursive solution ..

x0| x1| x2| x3| x4|... x_i-1| x_i|..x_n-1
  |   |   |   |   |         |    |       
                            ^
        this is "i"         |
                            first cut


  WE need to choose (K-1) cuts out of (n-1)..cuts shown above..
    Total ways -> (N-1
                       C
                         K-1)..
 Example :- [10, 20, 30, 40];
            K = 2..we need to choose 1  cut of 3 cuts..

                n-1      
mp(n, k) = min (max (mp(i, k-1), sum(ar, i, n-1)))
                i=1

mp(1, k) = ar[0];

mp(n, 1) = sum(ar, 0, n-1)..


ar[0]| ar[1]| ar[2]| ....ar[i-1]| ar[i]|....ar[n-1]
     |      |      |            |      |               
                                ^       
    --  this is "i, k-1" --     |      -- sum(i, n-1) --
                            first cut
*/

#include<bits/stdc++.h>
using namespace std;

int sums(int ar[], int b, int e){   // b->begin .. e-> end..
  int s = 0;
  for (int i = b; i<=e; i++){
    s += ar[i];
  }
  return s;
}
      // It is slow because of it try every solution..outcome..
int min_pages(int ar[], int n, int k){
  if (k == 1){
    return sums(ar, 0, n-1);
  }
  if (n == 1){
    return ar[0];
  }

  int res = INT_MAX;

  for (int i=1; i<n; i++){
    res = min(res, max(min_pages(ar, i, k-1), sums(ar, i, n-1)));
  }
  return res;
}

int32_t main(){
  int n, k;
  cin >> n >> k;

  int ar[n];
  for(int i=0; i<n; i++){
    cin >> ar[i];
  }

  cout << min_pages(ar, n, k);
  return 0;

  
}
