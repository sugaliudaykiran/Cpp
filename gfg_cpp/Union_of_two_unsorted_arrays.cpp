#include<bits/stdc++.h>
#include<vector>
#include<set>
using namespace std;

/*
            Navie - Solution :=         TC --> O(m*m + n*(m+n)).. were m is size of a[].. n is size of b[]
    1) Initialize : res = 0;
    2) Create an auxiliary array dist[];
    3) Traverse through a[]. for every element in a[].. check if it is present in dist[]..
        |->   If no then,   A) Increment res;
                            B) Append the element to dist[];
    4) Repeat step 3 for every element of b[];
    
*/

/*
                Efficient - Solution :=         TC -> 0(M+N).. AS -> O(M+N)
    1) Create an empty hash table, h {unordered_set},
    2) Insert all elements of a[] in h,         0(M)
    3) Insert all elements of b[] in h.         0(N)
*/

void uni(int a[], int b[], int m, int n){  //     TC -> 0(M+N).. AS -> O(M+N)
    unordered_set <int> s;          // here we can create distinct elements of a[] by s(a, a+m)..

    for (int i=0; i<m; i++){    // 0(M)
        s.insert(a[i]);
    }
    for (int j=0; j<n; j++){    // 0(N)
        s.insert(b[j]);
    }
    cout << s.size() << endl;
}

        // Using Constructor in efficient way :=
void unis(int a[], int b[], int m, int n){
    // unordered set directly with distinct elements..
    unordered_set <int> s(a, a+m);

    for (int j=0; j<n; j++){
        s.insert(b[j]);
    }
    cout << s.size() << endl;
}

int32_t main(){
    int m, n;
    cin >> m >> n;

    int a[m], b[n];

    for (int i=0; i<m; i++){
        cin >> a[i];
    }

    for (int j=0; j<n; j++){
        cin >> b[j];
    }

    uni(a, b, m, n);
    unis(a, b, m, n);
    



    return 0;
    // getline(cin , string_name) for reading strings..
}