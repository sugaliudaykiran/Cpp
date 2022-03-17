/*   
        First Circular Tour :-    
Consider an arrangement where n petrol pumps are arranged in a circular manner. 
   We need to find the first petrol pump from where we can visit all petrol pumps and
    come back to the petrol pump without ever going out of the petrol..


//   Navie - solution :-
        ** We maintain the cur_ptr at each (prt-dst).. and if cur_ptr reaches 
                less than 0 then break and check for another petrol bank..

//   Better Solution :-      Using a Deque..    TC -> O(N)..     AS -> O(N)..
        1) Keep adding items to the end of deque while cur_petrol is greater than or equal to zero.
        2) Keep removing items from the front of deque while cur_petrol is negative.
        ** In this cur_ptr will changes both in adding/removing..
        *** By Avoid Deque we can Circular array and using two pointer like start and end can optimise in AS -> O(1).. 
                but it takes 2N operations..
                
//   Efficient - Solution :-
        1) If cur_ptr becomes negative at P_i, then none of the petrol
                 pumps from P_0 to P_i can be solution..
        2) Let P_i be the first petrol pump where current petrol becomes negative, then 
                Cur_ptr =  i
                          ---
                          \               
                          /    (petrol[j] - distance[j])
                          ---
                          j = 0

        P_0, P_1, ....  P_i, P_i+1.... P_n-1

assuming :-             Here we are using prev_ptr to the cur_ptr..

        ** We travser from P_0.. where cur_ptr = (petrol[x] - distance[x])..
        ** on point of P_i we gets negative which is less than 0.. so we start from P_i+1.. and cur_ptr = 0..
        ** P_0 to P_i which is an Positive value.. and store on Prev_ptr..
        ** After P_i+1 to P_n   if.. cur_ptr is greater or equal to zero.. 
                then we traverse entire array and reached to P_i+1..
        **** Because, from P_0 to P_i the cur_ptr is non-negative so.. then from P_i+1 to P_n which is also non -negative.. 
        ** Check finally that cur_ptr - prev_ptr >= 0 then return (start +1) which position of that starting petrol bunk..
*/ 
                                                                                                                                             
#include<bits/stdc++.h>
#include<deque>
using namespace std;

//              Navie - Solution :-     TC -> O(N^2).. AS -> O(1)..
int firstPetrolPump(int ptr[], int dst[], int n){       
        for (int start=0; start<n; start++){
                int end = start, cur_ptr = 0;
                while(true){
                        cur_ptr += (ptr[end] - dst[end]);
                        if (cur_ptr < 0){
                                break;
                        }
                        end = (end + 1) % n;
                        if (end == start){
                                return (start + 1);       
                        }
                }
        }return -1;
} 

//      Efficient - Solution :-         TC -> O(N).. AS -> O(1).. in one traversal..
int fpp(int ptr[], int dst[], int n){
        int start = 0, cur_ptr = 0, prev_ptr = 0;
        
        for (int i=0; i<n; i++){
                cur_ptr += (ptr[i] - dst[i]);   //  In this we reached to next petrol bunk..
                if (cur_ptr < 0){
                        start = i+1;
                        prev_ptr += cur_ptr;
                        cur_ptr = 0;
                }
        }
        return ((cur_ptr - prev_ptr) >= 0)? (start +1): -1;
}

int32_t main(){
   int n = 4;
   int ptr[] = {4, 8, 7, 4};
   int dst[] = {6, 5, 3, 5};

   cout << firstPetrolPump(ptr, dst, n) << endl;
   cout << fpp(ptr, dst, n) << endl;
   return 0;
}