#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

void result(string str, int L)
{
    int n = str.size();
    unordered_set <string> s;

    for (int i=0; i<n-L+1; i++)
    {                               //  s.substr(Pos, Len)..
        string temp = str.substr(i, L);

        s.insert(temp);
    }    

    for (string x: s)
    {
        cout << x << " ";
    }cout << "\n";
}



int32_t main()
{   
    string str;
    cin >> str;

    int L;
    cin >> L;

    result(str, L);

    return 0;
}