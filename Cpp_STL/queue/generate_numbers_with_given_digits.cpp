#include<bits/stdc++.h>
#include<queue>
using namespace std;

void printFirstN(int n)
{                       //  TC -> O(n)..
    queue <string> q;
    q.push("5");
    q.push("6");

    for (int i=0; i<n; i++)
    {
        string x = q.front();
        cout << x << " ";
        q.pop();
        q.push(x+"5");
        q.push(x+"6");
    }
}


int32_t main()
{
    int n;
    cin >> n;

    printFirstN(n);
    return 0;
}