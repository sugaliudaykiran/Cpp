#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

string findwinner(string *ar, int n)
{
    string ans = "";
    int maxFreq = INT_MIN;

    for (int i=0; i<n; i++)
    {               //      TC -> O(N^2 * Max_length).. 
        int count = 1;
        for (int j=i+1; j<n; j++)
        {
            if (ar[i] == ar[j])
            {
                count++;
            }
        }

        if (count > maxFreq)
        {
            maxFreq = count;
            ans = ar[i];
        }
        else if (count == maxFreq)
        { // taking Lexiographic smaller one..
            if (ar[i] < ans)
            {
                ans = ar[i];
            }
        }
    }
    return ans;
}

string findwinner2(string *ar, int n)
{
    string ans = "";
    int maxFreq = INT_MIN;

    unordered_map <string, int> mp;  //  TC -> O(N* Max_length)..
    for (int i=0; i<n; i++)      // SC -> O(N* Max_length)..
    {
        mp[ar[i]]++;
    }

    for (auto x: mp)
    {
        if (x.second > maxFreq)
        {
            ans = x.first;
            maxFreq = x.second;
        }
        else if (x.second == maxFreq)
        {
            if (ans > x.first) // taking Lexiographic smaller one..
            {
               ans = x.first;
            }
        }
    }
    return ans;
}

// int32_t main()
// {
    // int n;
    // cin >> n;
    
    // string *ar = new string[n];
    // for (int i=0; i<n; i++)
    // {
    //     cin >> ar[i];
    // }            

    // cout << findwinner2(ar, n) << "\n";
    // return 0;

    
// }


int32_t main()
{
    vector <int> v({1, 2,3 ,4});
    for (int x:v)
    {
        cout << x << " ";
    }   
    return 0;
}