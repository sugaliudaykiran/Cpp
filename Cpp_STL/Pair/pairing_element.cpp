/*
 
 Output Format: For each testcase,in a new line,
  you need to print the pairs formed as such (arr[0],arr[N-1]) (arr[1],arr[N-2]), 
    and so on in new line.

*/ 
#include "bits/stdc++.h"

using namespace std;


vector<pair <int, int >> array_of_Pairs(int  arr[],int N)
{
    vector<pair<int, int>> res;
    
    int i=0, j=N-1;
    int indx = 0;
    
    while (i<j)
    {
        res.push_back({arr[i++], arr[j--]}) ;
    }
    
    if (N % 2 != 0 && i == j)
    {
        res.push_back({arr[i], arr[j]}) ;
    }
    return res;
}

int main()
{
    // cout<<"Hello World";
    int N;
    cin >> N;
    int arr[N];
    
    for (int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
    
    vector<pair <int, int>> res = array_of_Pairs(arr, N);
    
    for (auto x: res)
    {
        cout << "{" << x.first << " " << x.second << "}" << " ";
    }cout << "\n";
    
    return 0;
}