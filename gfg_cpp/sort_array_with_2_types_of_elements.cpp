/*  Sort an Array with two types of elements :- 
        a famous interview problem in which you need to segregate an array of elements containing two types of elements. 
        These Similar types are:
            1) Segregate negative and positive elements.    {-3, -1, 2, 4}
            2) Segregate even and odd elements.             {4, 6, 5, 1}
            3) Sort a binary array.                         {0, 0, 1, 1}    

*/

#include<bits/stdc++.h>
using namespace std;
// Segregate an array of elements containing two types of elements.  {-3, 2, 4,-1} -->  {-3, -1, 2, 4}

// Navie - Solution :-                  TC -> 0(N).. Which is three Traversals.. AS -> 0(N)..
void segregate(int ar[], int n){
    int temp[n], j = 0;
    for (int i=0; i<n; i++){
        if (ar[i] < 0){
            temp[j] = ar[i];
            j++;
        }
    }
    for (int i=0; i<n; i++){
        if (ar[i] > 0){
            temp[j] = ar[i];
            j++;
        }
    }
    for (int i=0; i<n; i++){
        ar[i] = temp[i];
    }
}

/* Efficient - Solution :-   
    Idea :- This Problem is mainly a Variation of partition() of Quick sort..
        ==> Hoare (or) Lomuto Partition can solve this is TC -> 0(N)..Time and AS -> 0(1)..
        ==> It is a Single Traversal..
*/

void Hoare_p(int ar[], int n){      // In this we consider first element as Pivot..
    int i = -1, j = n;              
    
    while (true){                   // TC -> 0(N).. and AS -> 0(1)..
        do{
            i++;
        }while(ar[i] < 0);
        do{
            j--;
        }while(ar[j] >= 0);
        if (i >= j){
            return;
        }
        swap(ar[i], ar[j]);
    }
}
// Similar Try for remaining examples..{2, 3}..

int32_t main(){

    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // segregate(ar, n);
    
    Hoare_p(ar, n);
    for (int s: ar){
        cout << s << " ";
    }
    return 0;
}