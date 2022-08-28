#include<bits/stdc++.h>
using namespace std;

bool myCmp(const pair<int, int>&p1, const pair<int, int>&p2)
{
    double r1 = (double)p1.first/p1.second;
    double r2 = (double)p2.first/p2.second;

    return r1 > r2;
}

double fknaps(pair <int, int> ar[], int n, int weight)
{       //                      TC -> O(N logN + N)..
    double ans = 0.0;           // SC -> O(1)
    sort(ar, ar+n, myCmp);

    for (int i=0; i<n; i++)
    {
        if (weight >= ar[i].second)
        {
            weight -= ar[i].second;
            ans += ar[i].first;
        }
        else if (weight < ar[i].second){
            ans += ar[i].first * (double)weight/ar[i].second;
            break;
        }
    }
    return ans;
}

int32_t main()
{
    pair <int, int> ar[] = {{120, 30}, {100, 20}, {60, 10}};
                        // {value, weight}
                        //  {60, 10}, {100, 20}, {120, 30}..
    int weight = 50;

    double ans = fknaps(ar, 3, weight);
    cout << ans << "\n";
    // Idea :- Finding the items where val/weight has maximum units..
            // Sort the items in decreasing order based on the val/weight..


    return 0;
}
