#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int32_t main()
{
    vector <int> v1 = {10, 20, 30, 40};
    vector <int> v2 = {20, 40, 30, 10};
                        //  TC -> O(n^2)..
    if (is_permutation(v1.begin(), v1.end(),v2.begin()))
    {
        cout << "Yes.." << "\n";
    }
    else{
        cout << "No.." << "\n";
    }


    int ar1[] = {1, 2, 4, 5};
    int ar2[] = {5, 3, 1, 2};

    if (is_permutation(ar1, ar1+4, ar2))
    {
        cout << "Yes.." << "\n";
    }
    else{
        cout << "No.." << "\n";
    }

    return 0;
}