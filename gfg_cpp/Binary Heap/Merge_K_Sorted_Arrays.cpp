/*

Merge K Sorted Arrays   :-
    In this we discusses, the problem of how to Merge K Sorted Arrays.

    1) We are given K sorted array we need to merge them into one sorted array..
    Ex.,        ar[][] = [[10, 20, 30],
                          [5, 15],
                          [1, 9, 11, 18]]
            res[]  = [1, 5, 9, 10, 11, 15, 18, 20, 30]

    Ex2.,       ar[][] = [[5, 20, 30],
                          [1, 2]]
                res[] = [1, 2, 5, 20, 30]
    2) In C++ we assums that it is vector of vector as input and return vector..

    Super Naive Code :-         TC -> O(nk lognk)..
        1) Put all elements in res[]
        2) Sort res[]
        3) Time complexity :  O(nk lognk)..
            where k is the number of input array..
                  n is the maximum numbers of elements in array..
                  
    Naive Code  :-              TC -> O(n(k^2))..        
        1) Copy the first array to res[]
        2) Do following for remaining arrays starting from the second merge current array into res[] 
           using merge sort which take O(m) + O(n).. where m is size of first array and n is the size of second array..
        3) Time Complexity :-   
                O(n + 2n + 3n.... kn)    => O(n)*(k(k+1)/2)..  where k is sum of the series..
                    =>  O(n(k^2))

    Efficient Code  :-          TC -> O(nk logk)..
        1) In this we use Min heap DS to merge the sorted array..
        2) Here Min Heap contains object of a class.. this class three 
            members they are value, Position of array, Position of value in the array..
        Ex., ar[][] = [[10, 20, 30],
                        [5, 15],
                        [1, 9, 11, 18]]
            for example in this 1 is value and it's array position of array is 2, and position of value in array is 0..
                            for 30 is value and it's array position of array is 0, and position of value in array is 2..
        3) Initial we insert the first value of all the given arrays into Min heap..
        4) Next Extract min and insert next item of the same array..
        5) This Extract items are insert to the result array..
        6) If in case the elements of an array is passed to heap completed and remains 
            nothing then we done of the array.. and check remaining array to complete..
        7) Finally the result array contains merge of all arrays in sorted order..

*/ 

#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct Triplet{
    int val, apos, vpos;
    Triplet(int v, int ap, int vp){
        val = v;
        apos = ap;
        vpos = vp;
    }
};

struct Mycmp{
    bool operator()(Triplet &t1, Triplet &t2){
        return t1.val > t2.val;
    }
}; 

vector<int> MergeAr(vector<vector <int>> &ar){      //  TC -> O(nk logk).. where n is max no.of elements.. k is no of arrays.. in Heap contains at most K elements..
    vector <int> res;
    priority_queue<Triplet, vector<Triplet>, Mycmp> pq;

    for (int i=0; i<ar.size(); i++){
        Triplet t(ar[i][0], i, 0);
        pq.push(t);
    }

    while (pq.empty() == false){
        Triplet cur = pq.top();
        pq.pop();
        res.push_back(cur.val);
        int ap = cur.apos, vp = cur.vpos;
        if (vp+1 < ar[ap].size()){
            Triplet t(ar[ap][vp+1], ap, vp+1);
            pq.push(t);
        }
    }
    return res;
}

int32_t main(){
    vector<vector<int>> ar = {{5, 10},
                              {4, 9},
                                {6}};
    vector <int> r = MergeAr(ar);
    for (auto x: r){
        cout << x << " ";
    }cout << endl;

    return 0;
}