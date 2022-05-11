/*

    Pair :-    
        Pair is used to combine together two values that may be different in type.
          Pair provides a way to store two heterogeneous objects as a single unit.

         It is basically used if we want to store tuples. The pair container is a simple container 
            defined in <utility> header consisting of two data elements or objects. 

    Ref :- https://www.geeksforgeeks.org/pair-in-cpp-stl/
    Ref2:- https://www.cplusplus.com/reference/utility/pair/

    The first element is referenced as ‘first’ and the second element as ‘second’ and the order is fixed (first, second).
        Pair can be assigned, copied, and compared. The array of objects allocated in a map or hash_map is of type
             ‘pair’ by default in which all the ‘first’ elements are unique keys associated with their ‘second’ value objects.
        To access the elements, we use variable name followed by dot operator followed by the keyword first or second.
    
    Syntax:
         pair (data_type1, data_type2) Pair_name

    ** Pair is a way of creating a Composite-Datatype composed of 2 different primitive/composite datatypes.
            pair <int, int> p;      //  a pair of 2 ints..
            pair <int, string> p;   //  a pair of an int and a string..
            pair <int, pair<int, string>> p;    //  a pair of int and (a pair of int and a string)..   Composite Datatype..
            pair <vector<int>, string> p;       //  a pair of a (vector of int) and a string..          Composite Datatype..
            pair<vector<pair<int, int>>, string> p;


        Access elements using .first and .second
    pair <string, int> p = {"hello", 6};
    cout << p.first << " " << p.second << "\n";         //  prints: hello   6

------------------------------------>

pair <int, int> f()
{
    return {3, 4};
}   //  Normal fuctions can return one value at a time..
    //  but using pair we can return a pair of function return..    it requires in-case of return Quotient and remainder..

int32_t main()
{
    pair <int, string> p = {4, "uday"};
    p.first = 7;       //   update p's first..
    
    cout << p.first << " " << p.second << "\n";     // fetch the first and second of pair..
    
    pair <int, int> p2 = f();
    cout << p2.first << " " << p2.second << endl;   

    return 0;
}

------------------------------------>
sorting arrays/vectors of Pairs

say we have an array of pairs.
    pair <int, int> p[5];   //  an array of 5 pairs
        p[0] = {1, 2};  p[1] = {5, 2};  p[2] = {8, 1};  p[3] = {1, 0};  p[4] = {3, 4};
    Let's sort this array..

    sort(p, p+5);
        Now the array looks like :
        [{1, 0}, {1, 2}, {3, 4}, {5, 2}, {8, 1}]  
    //  sorting is done in a way that the ordering is done by the "first" element, 
    //      but wherever the first are equal. the ties are broken by comparing second.


    pair <int, int> p[5];   //  array of 5 pairs..

    p[0] = {1, 2};  p[1] = {5, 2};  p[2] = {8, 1};  p[3] = {1, 0};  p[4] = {3, 4};

    sort(p, p+5);

    for (int i=0; i<5; i++)
    {
        cout << p[i].first << " " << p[i].second << endl;
    } 

//  Given a list of name, scores of students, print the names of students in decreasing order of their scores..

*/

#include<bits/stdc++.h>
#include<string>
using namespace std;

/*

bool comp(const pair<int, int>& a, const pair<int,int>& b){
    if (v[a.first]>v[b.first]) {
        return true;
    }
    else if(v[a.first] == v[b.first] && a.second < b.second){
        return true;
    }
    return false;
}
In other words, the sorted array will be sorted to deliver values of v in descending order.
     For values that are equal, the array is sorted according to the second
         variable in ascending order.
*/ 

bool myCmp(const pair <int, string> &a1, const pair <int, string> &a2)
{
    return a1.first > a2.first;
}

int32_t main()
{   
    //  Given a list of name, scores of students, print the names of students
        //   in decreasing order of their scores..      Ref :-  https://www.geeksforgeeks.org/sorting-vector-of-pairs-in-c-set-2-sort-in-descending-order-by-first-and-second/

    vector <pair <int, string>> v;      //  vector of pairs..
    
    int ar[] = {10, 7, 5, 1};
    string ar1[] = {"geetha", "uday", "sai", "lokesh"};

    for (int i=0; i<4; ++i){
        v.push_back(make_pair(ar[i], ar1[i]) );
    }

    sort(v.begin(), v.end(), myCmp);   //  Here we can use function to get in decreasing order.. by compare first value..
                                        //  or using    sort(v.rbegin(), v.rend());


    for (int i=0; i<v.size(); ++i){
         cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;

}









