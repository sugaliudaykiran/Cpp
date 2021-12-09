#include<bits/stdc++.h>
using namespace std;

void swap(int x, int y){  // pass by value..
    int temp = x;
    x = y;
    y = temp;
}

void swap2(int *x, int *y){   // pass by reference or address..
    int temp = *x;
    *x = *y;
    *y = temp;
}

void increment(int *n){
    n++;
}

int32_t main(){
    int x, y;
    cin >> x >> y;

    swap(x,y); // here we are passing the value to function not address...!
    cout << x <<"  "<< y << endl;

    int *x_ptr = &x, *y_ptr = &y;
    swap2(x_ptr,y_ptr);  // here we are passing the address of value to the function..!
    // we can use the below one which simple..!
    // swap2(&x, &y);
    cout << x << "  " << y << endl;
// ------->
    int n;
    cin >> n;
    increment(&n);

    cout << n << endl;

    return 0;
}