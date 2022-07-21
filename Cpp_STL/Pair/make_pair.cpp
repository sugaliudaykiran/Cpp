/*
 
User Task: You need to complete the function makePair(X, Y) that takes two numbers as parameters and returns a pair of these number. The first number is the first member of pair and second number is the second member.
 The printing is done by the driver code.

*/ 
#include "bits/stdc++.h"

using namespace std;


pair <int, int > make_pair(int x,int y)
{
    pair<int, int> res = {x, y};
    return res;
}

int main()
{
    // cout<<"Hello World";
    int t;
    cin >> t;

    while (t--)
    {
        int x, y;
        cin >> x >> y;

        pair<int, int> res = make_pair(x, y);
        cout <<"{" <<  res.first << "," << res.second<< "}" << "\n";
    }

    
    return 0;
}