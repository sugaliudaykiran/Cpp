#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;
        int digit_sum = 0;
        while (n)
        {
            int last_digit = n % 10;
            digit_sum += last_digit;
            n /= 10;
        }
        cout << digit_sum << endl;
    }

    return 0;
}