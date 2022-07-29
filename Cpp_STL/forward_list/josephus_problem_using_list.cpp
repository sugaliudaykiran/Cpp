/*

 Josephus Problem (or Josephus permutation) is a theoretical problem. Following is the problem statement:

    There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. 
        In each step, a certain number of people are skipped and the next person is executed.
         The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. 
         Given the total number of person n and a number k which indicates that k-1 persons are skipped and the kth person is killed in a circle. The task is to choose the place in the initial circle 
            so that you are the last one remaining and so survive.
    For example, if n = 5 and k = 2, then the safe position is 3. Firstly, the person at position 2 is killed, 
        then the person at position 4 is killed, then the person at position 1 is killed. 
            Finally, the person at position 5 is killed. So the person at position 3 survives. 
    If n = 7 and k = 3, then the safe position is 4. The persons at positions 3, 6, 2, 7, 5, and 
        1 are killed in order, and the person at position 4 survives.

*/ 

#include<bits/stdc++.h>     // Ref :-  https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/
#include<list>          //  Best solution :- TC -> O(n)..
using namespace std;

int getsurv(int n, int k)
{
    list <int> l;
    for (int i=0; i<n; i++)
    {
        l.push_back(i);     //   TC -> O(n*k)..  SC -> O(n)..
    }

    auto it = l.begin();

    while (l.size() > 1)
    {
        for (int count = 1; count < k; count++)
        {
            it++;
            if (it == l.end())
            {
                it = l.begin();
            }
        }
        
        it = l.erase(it);   //  removes the Kth_item and points to next item to it..
        if (it == l.end())
        {
            it = l.begin();
        }
    }
    return *(l.begin());
}


int josephus(int n, int k)  //  TC -> O(n).. SC -> O(n)..
{
    if (n == 1)
        return 1;
    else
        /* 
            The position returned by josephus(n - 1, k) is adjusted because the recursive call
                josephus(n - 1, k) considers the original position k % n + 1 as position 1 
        */
        return (josephus(n - 1, k) + k - 1) % n + 1;
}

int32_t main()
{
    int n, k;
    cin >> n >> k;

    cout << getsurv(n, k) << "\n";

    return 0;
}