#include<bits/stdc++.h>
using namespace std;

void PairDemo()
{
    //  pair <first, second> p;     In pair we can create with any data or any container type.
    pair <int, string> p;   
    // p = make_pair(1,"abc");
    p = {1, "abc"};

    //  We can copy pair also,
    pair <int, string> p1 = p;    //    simple coping the values..  
    p1.first = 10; 
    //  By adding reference we can change the value.
    pair <int, string> &p2 = p;
    p2.first = 20;

    cout << p.first << " " << p.second << endl;

    //  Pair is mostly used to maintain relation of something of something..
    int a[] = {1, 2, 3};
    int b[] = {3, 4, 5};    //  In this we assuming the each index values are having relation with both arrays,

    pair <int, int> P_ar[3];    //  Here in mostly case, vector of pair is used.
    P_ar[0] = {1, 3};
    P_ar[1] = {2, 4};
    P_ar[2] = {3, 5};
    
    // swap(P_ar[0], P_ar[2]);      Here we say that by using pair we can maintain a relation with one another,
    for (int i=0; i<3; ++i)                         //  (sizeof(P_ar)/sizeof(P_ar[0]));
    {
        cout << P_ar[i].first << " " << P_ar[i].second << endl;
    }

    //  We can take pair input like,
    pair <int, string> P;
    cin >> P.first;
    cin >> P.second;

    cout << P.first << " " << P.second << endl;

}

void PrintVector(vector <string> &v)    //  Here copy takes expensive operations.. so need to use References..
{   
    cout << "size: " << v.size() << endl;       //  v.size() -> O(1)..
    for (int i=0; i<v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    // v.push_back(1);     //  Here we can prove that it creates a copy of calling vector so,
                //   by adding a item it should be display on next call of it.
    cout << endl;
}

/* 
void VectorDemo()
{
    vector <int> v;     // Vector which is an continous memory blocks and It is an 'Dynamic sized array'.
    int n;              //  Vector can be any data type and which includes containers like set, map, including pairs.
    cin >> n;   
    for (int i=0; i<n; ++i)
    {  
        int x;
        cin >> x;
        PrintVector(v);
        v.push_back(x);     //  O(1)..
    }
    PrintVector(v);

    //  In local declaration array which is between 10 to_pow(5)..
    //  In global declaration array of which is between 10 to_pow(7)..
    //       as similiar in vector also.. This limitation which on the continous memory allocation like array/vectors.


    vector <int> v(5, 3);
    v.push_back(5);         //  O(1)..
    // PrintVector(v);   
   
    v.pop_back();       //  O(1)..  which remove the last item from vector.
    // PrintVector(v);   

    vector <int> v2 = v;        // Here we copying the vector.. and change doesn't effect.  but by using refernces. it will effects original.. 
    v2.push_back(2);            //  copying which takes O(n)..  which is an expensive operation.
    PrintVector(v); 
    PrintVector(v);             //  Here it's adding added the '1' to the vector.  
    PrintVector(v2);            //  In above the function which is creating a copy on calling vector. 
}
*/

int32_t main()
{                   
    vector <string> v;
    int n;
    cin >> n;
    for (int i=0; i<n; ++i)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    PrintVector(v);
    return 0;
}