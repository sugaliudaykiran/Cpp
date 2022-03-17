/*

    Deque in C++ STL
    ** Deque Provides Fuctionality of both stack and queue..
    ** In Deque we can insert/delete on the both the ends..
    ** In cpp Deque has some additional properities than Doubly end queue.. that is Random access and Oribit number of insertion in O(1)..
    ** This has similiar container methods like rbeing(), rend(), cbegin(), cend(),crbegin(), crend().  c -> constant  r-> reverse.. iterators..
    
    ** How does deque work internally ?         
                                               |       |
            |    p[0]     |                    |data[0]|    <- begin()
            |    p[1]     |
            | Pointer[2]  |        ->          |data[1]|
            |    p[3]     |                    |data[2]|
            |    p[4]     |
            |    p[5]     |                    |data[3]|
                                               |data[4]|    
                                               |       |  <-  end()
    
    ** In Doubly linked list which provides the push_back(), pop_back(), push_front(), push_back()..
            but which does not provides "Random access"..
    ** So, we use Circular array.. and it has a problem.. it was if size increase then it takes Costly Operations.. it create Doubly size array..
    ** In deque, it uses data in Blocks and linked with the Pointer.. if Pointer size is full then it does Doubly.. 
            It does not copy the entire data, just it uses Pointers..   So it O(1)..
            But in Pointer which takes constant for calling calls   So.. its  O(1)..
    
    ** Push_back(X), Push_front(X), Pop_back(), Pop_front(), [] -> accessing the random item..
    ** Insert() and erase() takes O(N).. because contigous memory location..
    
    **** Push_back(), Push_front() which do constant copy constructor calls.. so it O(1)..

    Some methods :-
        insert and erase
        begin, insert, pop and size
        push, front and back
*/ 

#include<bits/stdc++.h>
#include<deque>
using namespace std;

int32_t main(){
    deque <int> dq = {10, 20, 30};         //  we can create without assign values also it takes empty initial..

    dq.push_front(5);
    dq.push_back(35);

    for (auto it: dq){              //  for each loop (or) we can use iterator.. by dq.begin() to dq.end()
        cout << it << " "; 
    }cout << endl;

    cout << dq.front() << " " << dq.back() << endl;


    auto i = dq.begin();    //  begin() which is pointing to first item of deque..
    i++;                    //  end() which is pointing to beyound the last item.. 
    dq.insert(i, 7);       //  insert(iterator_pointing, item) on pointing the item is inserted before..   {5, 7, 10, 20, 30, 35}
    dq.pop_front();        //   remove front item..
    dq.pop_back();          //  remove back/rear item..
    cout << dq.size() << endl;      // return size..

    return 0;
}