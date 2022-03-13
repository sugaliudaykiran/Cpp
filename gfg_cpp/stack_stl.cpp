/*

Applications of Stack :-
    1) Function Calls.
    2) Checking for Balanced Paranthesis.
    3) Reversing Item.
    4) In-fix to Pre-fix/Post-fix.  {Every operator has fixed Number of operands..}
    5) Evaluation of Post-fix/Post-fix.
*** 6) Stock span Problem and its Variations.
**  7) Undo/Redo (or) Forward/Backward of Browser..

    Stack In STL :-
    __   push()
    |    pop()
    |    size()             // TC -> O(1)...
    |    empty()
    |_   top()
        
    ** Stack can be Implemented on any underlying container that provides following operations :-
            back()
            empty()
            push_back()
            pop_back()
            size()
    ** List, vector, Dequeu which allows this functionalities..
    ** By Default Dequeu is implemented..
    ** Since the Stack can be implemented using other container, 
            and works as Interface..  so Stack is also known as "Container Adapter" {like queue, partie queue}

*/

#include<bits/stdc++.h>
#include<stack> //          FILO (or)   LIFO
using namespace std;

int32_t main(){
    stack <int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl;
    st.pop();               //  pop() in STL which is Void type.. doesn't return..
    cout << st.top() << endl;
    cout << st.size() << endl;
    cout << endl;

    st.push(30);
    st.push(40);
    
//  using empty() we can print the item of stack, it follow's  LIFO..{which reverse the items..}
    while (st.empty() == false){
        cout << st.top() << " ";
        st.pop();
    }cout << endl;

    return 0;
}