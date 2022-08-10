#include<bits/stdc++.h>
#include<queue>
using namespace std;

//      Navie Solution :-
void PrintK_LargestEle(int *ar, int n, int k)
{
    sort(ar, ar+n);     //  TC -> O(nlogn)..
    for (int i=n-k; i<n; i++)
    {
        cout << ar[i] << " ";
    }cout << "\n";
}

//   Better Solution :-  TC -> O(n + kLogn)
void PrintK_LargestEle2(int *ar, int n, int k)
{   //  Using MaxHeap..
    priority_queue<int> pq(ar, ar+n);
    for (int i=0; i<k; i++)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

//  Efficient Solution :-  TC -> O(K + (n-K)LogK)
void PrintK_LargestEle3(int *ar, int n, int k)
{   //  Using MinHeap..
    priority_queue<int, vector<int>, greater<int>> pq(ar, ar+k);

    for (int i=k; i<n; i++) //  N-K..
    {
        if (pq.top() < ar[i])   
        {
            pq.pop(), pq.push(ar[i]);
        }
    }

    while (pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
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

    PrintK_LargestEle3(ar, n, k);
    return 0;
}