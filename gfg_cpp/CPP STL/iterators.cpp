/*

    Iterators :-    
        An iterator is an object (like a pointer) that points to an element inside the container. 
            We can use iterators to move through the contents of the container.
            They can be visualized as something similar to a pointer pointing to some location
                and we can access the content at that particular location using them

    Ref :- https://www.geeksforgeeks.org/introduction-iterators-c/#:~:text=An%20iterator%20is%20an%20object,that%20particular%20location%20using%20them.

    Note :-     v.end() is the iterator to a non existent element (after the last element..)
   
Iterator is behave a lot like pointers..
    vector <int> v = {10, 15, 12, 5, 20};                       int ar[5] = {10, 15, 12, 5, 20};
    vector <int>::iterator it = v.begin();                      int *p = ar;
             or     
    auto it = v.begin();    //  "auto" keyword is used to deduce datatype automatically..

    cout << *it << endl;    //  10                              cout << *p << endl;     //  10
    it++;                                                       p++;
    cout << *it << endl;    //  15                              cout << *p << endl;     //  15
    it--;                                                       p--;
    cout << *it << endl;    //  10                              cout << *p << endl;     //  10
    cout << *(it + 3) << endl;  //  5                           cout << *(p + 3) << endl;   //  5

*/

#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    vector <int> v = {10, 15, 12, 5, 20};
    auto it = v.begin();
    for (; it != v.end(); it++)      
    {
        cout << *it << " ";
    }cout << endl;
    return 0;
}