/*
    All operations are in O(1) time complexity in deque..
*/

#include<bits/stdc++.h>
#include<deque>
using namespace std;

deque <int> dq;

void insertMax(int x)
{
    dq.push_back(x);
}

void insertMin(int x)
{
    dq.push_front(x);
}

int getMin()
{
    return dq.front();
}

int getMax()
{
    return dq.back();
}

int extractMin()
{
   int temp = dq.front();
    dq.pop_front();
    return temp;
}

int extractMax()
{
    int temp = dq.back();
    dq.pop_back();
    return temp;
}


int32_t main()
{               // All operations are in O(1)

    insertMin(5);
    insertMax(20);
    insertMin(2);
    cout << getMin() << "\n";
    
    insertMax(30);
    insertMin(1);
    cout << getMax() << "\n";
    cout << getMin() << "\n";
    
    cout << extractMin() << "\n";
    cout << extractMax() << "\n";
    return 0;
}