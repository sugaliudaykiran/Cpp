/*

    YT :- https://www.youtube.com/watch?v=g-1Cn3ccwXY&t=16s
    

*/
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
using namespace std;

bool myCmp(int x, int y)
{
    return (x > y);
}

void VectorDemo()
{
    vector <int> v = {11, 2, 3, 14};
    cout << v[1] << endl;

    sort(v.begin(), v.end());       //  O(N logN)
    //  2, 3, 11, 14

    //  O(logN)     finding an element..
    bool present = binary_search(v.begin(), v.end(), 11);   //  true.
    cout << present << endl;
    present = binary_search(v.begin(), v.end(), 1);     //  false.
    cout << present << endl;

    //  inserting elements..
    v.push_back(100);
    present = binary_search(v.begin(), v.end(), 100);   //  true.
    cout << present << endl;

    v.push_back(100);
    v.push_back(100);
    v.push_back(100);
    v.push_back(100);
    v.push_back(123);
    //  2, 3, 11, 14, 100, 100, 100, 100, 100, 123
    
    //  finding position of first occurances of 100 using iterator..    // lower and upper takes O(logN) in sorted vector..
    vector <int> :: iterator it = lower_bound(v.begin(), v.end(), 100);     //  >=
    vector <int> :: iterator it2 = upper_bound(v.begin(), v.end(), 100);    //  >

    cout << *it <<  " " << *it2 << endl;
    cout << it2 - it << endl;   //  finding the frequency (or) count of 100 using lower and upper_bounds..
                                //  it takes O(1).. arithmatic opertions on iterators.. 

    // sorting vector in decreasing order..     using overloaded function called myCmp fun..
    sort(v.begin(), v.end(), myCmp);

    vector <int> :: iterator it3;
    for (it3 = v.begin(); it3 != v.end(); it++)
    {
        cout << *it3 << " "; 
    }cout << endl;

    //  C++ uses auto in-place of iterator declartion.. and using for each loop.
    auto it4 = v.begin();
    for (int &x: v)         //  By using 'reference' we can update value content..
        x++;

    for (int x: v)
        cout << x << " ";
    cout << endl;   //  Here we are insertion and sorting and making iteration..    
}


void SetDemo()
{
    set <int> S;    //  It maintains every movement in the sorted order..
    S.insert(1);
    S.insert(2);
    S.insert(3);    //  O(logN).. insertion takes
    S.insert(-1);
    S.insert(-10);

    for (int x: S)      
        cout << x << " ";
    cout << endl;

    //  -10, -1, 1, 2, 3
    auto it = S.find(-1);
    if (it == S.end())
    {
        cout << "Not Present\n";
    }
    else
    {
        cout << "Present\n";
        cout << *it << endl;
    }

    auto it2 = S.lower_bound(-1);   //  which returns >=    and takes O(logN)..
    auto it3 = S.upper_bound(0);    //  Stricly greater than '0'  >
    auto it4 = S.upper_bound(-1);   //  which iterating to upper bound of 0 and -1 which is '1'
    cout << *it2 << " " << *it3 << " " << *it4 << endl;
     
    auto it5 = S.upper_bound(3);    //  Upper_bound for last item of a Set.
    if (it5 == S.end())
    {
        cout << "Not Found..!" << endl;
    }
    else                //  We can erase an element from set in Log(N).. time and it's  S.erase(X);
    {
        cout << *it5 << endl;       //  pointing to S.end()..
    }
}

void MapDemo()
{
   map <int, int> m;    // Map is something like mapping to something to something.
   m[1] = 100;      //  Map is something like set in O(Log N) takes to map.
   m[2] = -1;       // You can also find/delete a key in a map or not in just Log(N) time 
   m[3] = 200;      //      m.find(key) and m.erase(key)
   m[10000] = 1;

    map <char, int> cnt;
    string x = "uday kiran";

    for (char c: x)     // which takes Linear time..
    {
        cnt[c]++;
    }
    cout << cnt['a'] << " " << cnt['z'] << endl;    //  2   0
}

void PowerOfStl()   
{
    //  Queries is add interval (x, y)  like add[2, 3]; add[10, 20]; add[30, 400]; add[401, 450]
    //       given me interval which contain the 'point'.  and above intervals are not be overlap.
    set <pair<int, int>> S;     // O(log N)..
    S.insert({401, 450});
    S.insert({2, 3});
    S.insert({10, 20});      // Ascending order in Pair :-  {a, b} and {c, d}
    S.insert({30, 400});   //  pair {a, b} is smaller than pair {c, d} if (a<b) or (a==b) and (c>b)
                                //   {2, 3}
                                //   {10, 20}
                                //   {30, 400}
                                //   {401, 450}; 
    int point = 402;

    auto it = S.upper_bound({point, INT_MAX});  //  By using INT_MAX we get next pointing pair which is greater than given point. 
    if (it == S.begin())
    {
        cout << "Not Found" << endl;
        return; //  In case of point is pointing to S.begin();
    }
    it--;
    pair <int, int> current = *it;
    if (current.first <= point and current.second >= point)
    {
        cout << "Found btw: " << current.first << " " << current.second << endl; 
    }
    else 
    {
        cout << "Not Found" << endl;    
    }
}//  Algorithm :- First we find the given point and INT_MAX in which greater to it..
        // and we decrement the iterator and check current pair has the point. or not..


void unordered_mapDemo()
{
    map <char, int> M;              //  insertion add(Key, value) and erase takes O(Log N)..    It uses 'BST' internally.. because it takes height of tree in worst case so it's balanced.. O(Log N)..
    unordered_map <char, int> U;    //  insertion add(Key, value) and erase takes O(1)..        It uses Hashing and indexing.. in case of collision O(N), it uses Linear probing method.. and soon.

    string s = "uday kiran";
    for (char c: s)
        M[c]++;     //  Takes O(N LogN)..   where N = |S|

    for (char c: s)
        U[c]++;     //  Takes O(N)..    
}
int main()
{
    //  C++ STL
    int n;
    cin >> n;
    long long S = 0;

    vector <int> v(n+5, 0);   // D. Array Division              // avoiding some segmentation fault..
    for (int i=0; i<n; i++)
        cin >> v[i], S += v[i];     //  Find the Sum..
                                             // |
    //  Given ->  [2, 2, 3, 4, 5]   => [2, 2, 4,| 3, 5]    now both parts are same sum..

    if (S & 1)
    {
        cout << "No\n";     //  Because if S is Odd answer doesn't exists..
        return 0;
    }

    map <long long, int> first, second; //      TRY for unordered_map also.. 
    
    first[v[0]] = 1;
    for (int i=1; i<n; i++)
    {
        second[v[i]]++;     //  Increment the value count.. incase if value is repeated..
    }
    long long sdash = 0;

    for (int i=0; i<n; i++)
    {
        sdash += v[i];
        
        if (sdash == S/2)       //  In case we are done that we get the left half equal to right half..
        {
            cout << "Yes\n";
            return 0;
        }
        if (sdash < S/2)    //  delete element from second half and insert to first half..
        {
            long long x = S/2 - sdash;      //  X lies on the second part..
            if (second[x] > 0)
            {
                cout << "Yes\n";
                return 0;
            }
        }
        if (sdash > S/2)        //  Here we are lookup for the 'Y' and above case 'X'
        {
            long long y = sdash - S/2;      //  Y lies on the first part..
            if (first[y] > 0)
            {
                cout << "Yes\n";
                return 0;
            }
        }
        //  i+1               Here we are adding and removing from the two parts.. 
        first[v[i+1]]++;
        second[v[i+1]]--;
    }
    cout << "No\n";


    return 0;
}