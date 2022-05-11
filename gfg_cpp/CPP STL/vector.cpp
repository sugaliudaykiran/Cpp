/*

    Benefits of the STL :-
        1) Using STL, you can write shorter code that runs faster.
        2) The Prewritten codes in STL are extremely error-free and optimized.
        3) As you study Advanced concepts - STL will be very important.
            -> Vector is used for graph adjancency list.
            -> Pairs and Sets are used for dijkstra algorithm in graph. and many more..
        
    Ref :- https://www.geeksforgeeks.org/vector-in-cpp-stl/
    Ref2 :- https://www.cplusplus.com/reference/vector/vector/

    Vector :-
        Vectors are same as dynamic arrays with the ability to resize itself automatically 

        when an element is inserted or deleted, with their storage being handled automatically by the container. 
             Vector elements are placed in contiguous storage so that they can be accessed and
             traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes 
             differential time, as sometimes there may be a need of extending the array. Removing the last element 
             takes only constant time because no resizing happens. Inserting and erasing at the beginning or in the middle 
             is linear in time.

    Certain functions associated with the vector are:
        Iterators

        begin() – Returns an iterator pointing to the first element in the vector
        end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
        rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
        rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
        cbegin() – Returns a constant iterator pointing to the first element in the vector.
        cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
        crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
        crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
*/ 

#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;

int32_t main()
{   
 
/*
    vector <int> v;
    cout << v.size() << "\n";
    //  Insert  -> O(1)..
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    
    cout << v[0] << " " << v[1] << " " << v[2] << endl;
    
    //  delete  -> O(1)..
    v.pop_back();
    cout << v.size() << "\n";       // size()  -> O(1)..

    v.push_back(13);

    cout << v[0] << " " << v[1] << " " << v[2] << endl;

    v.clear();                      //  clear()   -> O(n)..
    cout << v.size() << endl;

----------->

    vector <int> v(10);     //  {0, 0, .. 0}
    cout << v.size() << " " << v[0] << endl;

    vector <int> v2(5, 1);   //  {1, 1, ... 1}

    vector <int> v3[50];    //  This is array of 50 vectors..!!

    //  similiar we can declare string, char, bool type also..
    vector <bool> v(10, false);



    int n = 6;      //  Qes which contains elements, we need to print odd and even of it..
    vector <int> qes = {3, 2, 5, 3, 1, 4};
    vector <int> odd, even;
                                                        //  auto it -> vector <int> :: iterator it;     => https://www.geeksforgeeks.org/iterators-c-stl/
    for (auto it=qes.begin(); it!=qes.end(); it++)      //   'it' is an iterator    => https://www.geeksforgeeks.org/iterators-c-stl/
    {
        if (*it % 2 == 0)
            even.push_back(*it);
        else 
            odd.push_back(*it);
    }

    for (int x: odd)
    {
        cout << x << " ";     
    }
    
---------------->

    //  Sort()  :-  This function can be used to sort an array/vector or a string.
                      The underlying sorting algorithm is called the gcc_sort which is
                        hybrid algorithm which is implemented in a very efficient way. 
                      TC ->  O(N logN)..
        
        Sort(ptr to first_element, ptr to last_element +1)

    vector <int> v = {5, 4, 1, 3};  //  In case of vector and string we use iterators..

    sort(v.begin(), v.end());  //  sort(v.begin(), v.begin()+2);   It sorts the range first two elements..
    for (int x: v)
        cout << x << " ";
    cout << endl;
    
    //  In case of array :-

    int ar[4] = {6, 1, 3, 7};

    sort(ar, ar+4);             //  sort(ar, ar+2);      It sorts the range first two elements..
    for (int x: ar)
        cout << x << " ";

            
*/

    return 0;

}