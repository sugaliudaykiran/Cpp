/*

    Largest Rectangle with all 1's :-

        Navie - Solution :-     TC -> O(R^3 *C^3)..
        
        1) Begin with the starting item to all the items..
        2) In this it takes (R *C) times and visit every cell, 
            check the each cell, if the cell has the value 0 then just ignore it..
        3) If the cell has value 1 then try all the possible size (1,1), (1,2), (2,2),.. and soon..
        4) Compare the size with res.. and to generate the all possible size it takes (R *C).. time. inside the loop..
        5) So, it takes upper boundaries as (R^3 *C^3).. times..

        Efficient - Solution :-     TC -> O(R *C)..
            1) Here we uses the Largest Rectangle Area in a Histogram..
            2) First we traverse row wise of matrix and consider as the base of each Histogram..
            3) In traversing the row wise and update the matrix values.. if prev is 0 and cur is 1 then update it.. 
                0 -> 1 = 1, similiar, 1 -> 1 = 2.. and 2 -> 1 = 3.. and soon.
                in case of 1 -> 0 = 0... 0 -> 2 = 0..
            4) call the largest histogram function.. and check with res..
*/  

#include<bits/stdc++.h>
#include<stack>
using namespace std;

#define R 4
#define C 4

//      Largest Rectangle Area in a histogram :-
int rec(int ar[], int n){
    stack <int> st;
    int res = 0, tp, cur;

    for (int i=0; i<n; i++){
        while (st.empty() == false && ar[st.top()] >= ar[i]){
            tp = st.top();
            st.pop();
            cur = ar[tp]* (st.empty()? i: i-st.top() -1);
            res = max(res, cur);
        }
        st.push(i);
    }
    while (st.empty() == false){
        tp = st.top();
        st.pop();
        cur = ar[tp]* (st.empty()? n: n-st.top() -1);
        res = max(res, cur);
    }
    return res;
}

//  Efficient - Solution :-     input Matix is an Integer Matrix..
int maxRect(int mat[][C]){      //  TC -> 0(R*C).. AS -> O(C).. space for stack..
    int res = rec(mat[0], C);

    for (int i=1; i<R; i++){

        for (int j=0; j<C; j++){    // do for cummitivate values..
            if (mat[i][j]){
                mat[i][j] += mat[i-1][j];
            }
        }
        res = max(res, rec(mat[i], C));
    }
    return res;
}

int32_t main(){

    int mat[][C] = {{0, 1, 1, 0},
                     {1, 1, 1, 1},
                     {1, 1, 1, 1},
                     {1, 1, 0, 0}};

    cout << maxRect(mat);
    return 0;
}