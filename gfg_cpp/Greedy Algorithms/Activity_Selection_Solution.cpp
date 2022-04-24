/*

Activity Selection Solution :-
    In this we talks about C++ Solution of Activity Selection Problem.

*/ 

#include<bits/stdc++.h>
#include<climits>
#include<cmath>
using namespace std;

bool Mycmp(pair<int, int> a, pair<int, int> b){
    return (a.second < b.second);
}

int maxActivities(pair <int, int> ar[], int n){
    sort(ar, ar+n, Mycmp);
    int res = 1, prev = 0;

    for (int cur=1; cur<n; cur++){
        if (ar[cur].first >= ar[prev].second){
            res++;
            prev = cur;
        }
    }
    return res;
}

int32_t main(){
    pair <int, int> ar[] = {make_pair(12, 25), make_pair(10, 20), make_pair(20, 30)};
    int n = 3;
    cout << maxActivities(ar, n) << endl;

    return 0;
}