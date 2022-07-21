
#include "bits/stdc++.h"

using namespace std;


void corresp_Pair(int arr1[],char arr2[],int N, pair<int, char> res[]) 
{
    for (int i=0; i<N; i++)
    {
        res[i] = make_pair(arr1[i], arr2[i]);
    }    
}

int main()
{
    // cout<<"Hello World";
    int N;
    cin >> N;
    int arr1[N];
    char arr2[N];
    
    for (int i=0; i<N; i++)
    {
        cin >> arr1[i];
    }
    
   for (int i=0; i<N; i++)
   {
       cin >> arr2[i];
   }
    
    pair <int, char> res[N];
    
    corresp_Pair(arr1, arr2, N, res);
    
    sort(res, res+N);
    
    for (auto x: res)
    {
        cout <<  x.second <<" ";
    }cout << "\n";
    
    return 0;
}