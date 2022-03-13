/*
    Largest Rectangular Area in a Histogram (Part 1) :=
        The first part of the problem of calculating the Largest Rectangular Area in a Histogram.

        Navie - Solution :-     TC -> 0(N^2).. 

        ** Consider that very item in rectangle is smallest and find the area that cur_item begin the smallest..
        1) check each item prev and next sides, in traversing sides if cur_item should be smaller (or) equal to cur_item..
        2) In any item is smaller than break the loop.. if not then increment the count as adding itself.. as the smallest item..
        3) finally check if any max area over the item present.. 

    Ex :-   int ar[n] = {6, 2, 5, 4, 1, 5, 6};
    Initialize.. res = 0;
        i = 0: Cur = 6, res = 6;
        i = 1: Cur = 8, res = 8;
        i = 2: Cur = 5;
        i = 3: Cur = 8;
        i = 4: Cur = 7;
        i = 5: Cur = 10, res = 10;
        i = 6: Cur = 6;

        Better - Solution :-      TC -> O(N).. and takes 3 traversal and 2 stacks to store..
        
        1) Initialize : res = 0;
        2) Find Previous Smaller Element for every element.     takes..0(N)..
        3) Find Next Smaller Element for every element.         takes..0(N)..
        4) Do following for every element ar[i]
                Cur = ar[i]..
                Cur += (i - Ps[i] - 1)*ar[i];                  // Here it if stack is empty its item is "-1"
                Cur += (Ns[i] - i -1)*ar[i];                   // Here it if stack is empty its item is "n".. little change..
            res = max(res, Cur);                                 takes..0(N)..
        5) return res;

        ** In previous Greater element problem, in every item is processing that 
            every item with top stack is greater or equal.. push item (or) if smaller we are pop top of stack..
        ** In this Better - Solution.. we push to the stack when it's smaller (or) equal ..
            In case of greater we pop the top of stack..

    Efficient - Solution :- TC -> O(N).. and takes 1 traversal and 1 stacks to store..

        1) Create a stack, s..
        2) int res = 0..
        3) for (int i=0; i<n; i++){
            while (s.empty() == false && ar[s.top()] >= ar[i]){
                int tp = s.pop();
                int cur = ar[tp] * (s.empty())? i:(i-s.top()-1);    // to calculate the length of rectangle using prev, next..
                res = max(res, cur);
            }
            s.push(i);
        }
        4) while (s.empty() == false){
            int tp = s.pop();
            int cur = ar[top] * (s.empty())? n: (n-s.top() -1);     //  to calculate the length of rectangle using prev, with-out next..
            res = max(res, cur);
        }
        return res;
*/ 

#include<bits/stdc++.h>
#include<stack>
using namespace std;
    
    //      Navie - Solution :-     TC -> 0(N^2)..
int getmaxArea(int ar[], int n){
    int res = 0;
    for (int i=0; i<n; i++){
        int cur = ar[i];
        for (int j=i+1; j<n; j++){
            if (ar[i] <= ar[j]){
                cur += ar[i];
            }
            else break;
        }
        for (int k=i-1; k>=0; k--){
            if (ar[i] <= ar[k]){
                cur += ar[i];
            }
            else break;
        }
        res = max(cur, res);
    }
    return res;
}

//      Better - Solution :-        TC -> O(N)..
int getmaxArea2(int ar[], int n){
    int res = 0;
    int Ps[n], Ns[n];

    stack <int> s;
    s.push(0);
    for (int i=0; i<n; i++){
        while (s.empty() == false && ar[s.top()] >= ar[i]){
            s.pop();
        }
        int pse = (s.empty())? -1: s.top();
        Ps[i] = pse;
        s.push(i);
    }

    while (s.empty() == false){
        s.pop();
    }

    s.push(n-1);
    for (int i=n-1; i>0; i--){
        while (s.empty() == false && ar[s.top()] >= ar[i]){
            s.pop();
        }
        int nse = (s.empty())? n:s.top();
        Ns[i] = nse;
        s.push(i);
    }

    for (int i=0; i<n; i++){
        int cur = ar[i];
        cur += (i - Ps[i] -1)*ar[i];
        cur += (Ns[i] -i -1)*ar[i];

        res = max(res, cur);
    }
    return res;
}

//          Efficient - Solution :- TC -> O(N).. and takes 1 traversal and 1 stacks to store..
int rec(int ar[], int n){
    stack <int> st;
    int res = 0, tp, cur;

    for (int i=0; i<n; i++){
        while (st.empty() == false && ar[st.top()] >= ar[i]){
            tp =  st.top();
            st.pop();
            cur = ar[tp]* (st.empty()? i: i - st.top()-1);
            res = max(res, cur);
        }
        st.push(i);
    }
    while (st.empty() == false){
        tp = st.top();
        st.pop();
        cur = ar[tp]* (st.empty()? n: n - st.top() -1);
        res = max(res, cur);
    }
    return res;
}

int32_t main(){
    int n = 7;
    int ar[n] = {6, 2, 5, 4, 1, 5, 6};

    cout << getmaxArea2(ar, n);
    cout << endl;

    cout << getmaxArea(ar, n);
    cout << endl;

    cout << rec(ar, n);
    cout << endl;
    return 0;
}

/*

int largestHist(int arr[],int n) 
{ 
    stack<int> result; 
    int top_val; 
    int max_area = 0;  
    int area = 0; 
    int i = 0; 
    while (i < n) { 
        if (result.empty() || arr[result.top()] <= arr[i]) 
            result.push(i++); 
  
        else {  
            top_val = arr[result.top()]; 
            result.pop(); 
            area = top_val * i; 
  
            if (!result.empty()) 
                area = top_val * (i - result.top() - 1); 
            max_area = max(area, max_area); 
        } 
    } 
    while (!result.empty()) { 
        top_val = arr[result.top()]; 
        result.pop(); 
        area = top_val * i; 
        if (!result.empty()) 
            area = top_val * (i - result.top() - 1); 
  
        max_area = max(area, max_area); 
    } 
    return max_area; 
}

*/ 