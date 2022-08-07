#include<bits/stdc++.h>
#include<stack>
#include<queue>
using namespace std;    

void reverseK_item(queue <int> &q, int k)
{
    stack <int> st; //  TC -> O(n+k)..

    for (int i=0; i<k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    for (int i=0; i<q.size()-k; i++)
    {
        q.push(q.front());
        q.pop();
    }
    // cout << q.front() << "\n";
}

int32_t main()
{
    int  k;
    cin >> k;

    queue <int> q;
    
    int x;

    while (1)
    {
        cin >> x;
        if (x != -1)
            {
                q.push(x);
            }
        else
        {
            break;
        }
    }
   reverseK_item(q, k);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return  0;
}