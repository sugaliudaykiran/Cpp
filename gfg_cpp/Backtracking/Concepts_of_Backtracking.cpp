/*

Concepts of Backtracking    :-          Ref :-  https://www.geeksforgeeks.org/backtracking-introduction/
    In this we introduces to the Concepts of Backtracking

    Naive Code  :-
    Efficient Code(Using BackTracking)  :-

    Ref2 :- https://www.geeksforgeeks.org/backtracking-algorithms/
*/ 

#include<bits/stdc++.h>
#include<string>
using namespace std;

//      Using Backtracking :-   Removing recursive call of the invalid string..
bool isSafe(string str, int l, int i, int r)    //  TC -> !(n) around..
{
    if (l!=0 && str[l-1] == 'A' && str[i] == 'B')
    {
        return false;
    }
    if (r==(l+1) and str[i] == 'A' and str[l] == 'B')
    {
        return false;
    }
    return true;
}

//      Navie Solution :-   TC -> !(n) * n..
void permute(string str, int l, int r)
{
    if (l == r)
    {
        if (str.find("AB") == string::npos)
        {
            cout << str << " ";
        }return;
    }
    else
    {
        for (int i=l; i<=r; i++)
        {
            if (isSafe(str, l, i, r))
            {
                swap(str[i], str[l]);
                permute(str, l+1, r);
                swap(str[i], str[l]);
            }
        }
    }
}

int32_t main()
{
    string str = "ABC";
    permute(str, 0, str.length()-1);
    return 0;
}
