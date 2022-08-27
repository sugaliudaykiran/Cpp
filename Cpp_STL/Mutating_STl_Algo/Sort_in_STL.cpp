#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

struct points{
    int x, y;
};

bool myFun(const points&p1, const points&p2)
{
    // return (p1.x < p2.x);  // Increasing order on bases of 'x'..
    // return (p1.y < p2.y);  // Increasing order on bases of 'y'..
    // return (p1.x >= p2.x);  // Decreasing order on bases of 'x'..
    return (p1.y >= p2.y);     // Decreasing order on bases of 'y'..

}

int32_t main()
{
    int ar[] = {10, 2, 9, 5, 1};
    sort(ar, ar+5);   // Takes two iterator/address begin and end of the container..
                        // TC -> O(N logN)..
    for (int x: ar)  // Internally uses Intro Sort..
    {                // Intro sort which is combation of quick sort, heap sort, insertion sort..
        cout << x << " ";
    }cout << "\n";
    

    sort(ar, ar+5, greater<int>());
    for (int x: ar)
    {
        cout << x << " ";
    }cout << "\n";


    vector<int> v = {11, 5, 12, 8, 6};
    sort(v.begin(), v.end());
    for (int x: v)
    {
        cout << x << " ";
    }cout << "\n";

    sort(v.begin(), v.end(), greater<int>());
    for (int x: v)
    {
        cout << x << " ";
    }cout << "\n";


    points ar2[] = {{3, 10}, {2, 8}, {5, 4}, {1, 9}};
    sort(ar2, ar2+4, myFun);

    for (auto i: ar2)
    {
        cout << i.x << " " << i.y << "\n";
    }

    return 0;
}
