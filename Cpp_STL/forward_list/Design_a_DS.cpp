/*
    Design a Data structure, with insert(), replace(), print().. Operations.

    Insert(X)   :- Insert at the end..
    Print()     :- Print current sequency..
    Replace(X, seq) :-  Replace the first occurance of X with the given sequency..

    Ex:-

        insert(3), insert(5), insert(6), insert(3), print();
        replace(5, {1, 2, 3}), print();

    O/p :-  3 5 6 3 
            3 1 2 3 6 3

*/ 

#include<bits/stdc++.h>
#include<list>
using namespace std;

list <int> l;

void insert(int x)  //  TC -> O(1)..
{
    l.push_back(x);
}


void prints()   //  TC -> O(n)..
{
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *(it) << " ";
    }cout << "\n";
}
                                        //  TC -> O(Index * K).. where Index is X's first occurance and K is size of sequence..
void replace(int x, vector<int> &v) // we can use vector, list any thing.
{
    auto it = find(l.begin(), l.end(), x);  // finds the x's first occurance in the given list..
    
    if (it == l.end())  //  If the X is not present then return;
    {
        return;
    }

    it = l.erase(it);   //  erases the items and points to next of it..
    l.insert(it, v.begin(), v.end());   //  insert item/list in given address.. or before it..
}


int32_t main()
{
    
    insert(1);
    insert(3);
    insert(5);
    insert(3);
    prints();

    insert(7);
    vector <int> v(3, 9);

    replace(3, v);
    prints();

    return 0;
}
