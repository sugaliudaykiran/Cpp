#include<bits/stdc++.h>
#include<unordered_map>
using namespace std; 

//  Navie Solution :- 
void printDistWind(int *ar, int n, int k)
{
    for (int i=0; i<n-k+1; i++)
    {   // TC -> O((N-K)* k * k)
        int count = 0;
        for (int j=0; j<k; j++)
        {
            bool flag = false;
            for (int p=0; p<j; p++)
            {
                if (ar[i+j] == ar[p+i])
                {
                    flag = true;
                    break;
                }
            }
            if (flag == false)
            {
                count++;
            }
        }
        cout << count << " ";
    }
}

// Efficient Solution :-
void printDistWind2(int *ar, int n, int k)
{
    unordered_map <int, int> mp;
            //  TC -> O(N).. SC -> O(K)..
    for (int i=0; i<k; i++)
    {
        mp[ar[i]]++;
    }
    cout << mp.size() << " ";

    for (int i=k; i<n; i++)
    {
        // mp[ar[i-k]]--;
        if (--mp[ar[i-k]] == 0)
        {
            mp.erase(ar[i-k]);
        }
        mp[ar[i]]++;
        
        cout << mp.size() << " ";
    }
}




int32_t main()
{
    int n, k;
    cin >> n >> k;

    int *ar = new int[n];
    for (int i=0; i<n; i++)
    {
        cin >> ar[i];
    }

    printDistWind2(ar, n, k);

    return 0;
}