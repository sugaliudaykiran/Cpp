#include<bits/stdc++.h>
using namespace std;
//                                                       STACK
void func1(){
    // function_body;
}
void func2(){
    // function body;
}
void func3(){
    // function body;
}

int32_t main(){
    func1();            // stack is static memory allocation..which can't change memory allocation during RUNTIME. 
    func2();            // causes the stack-overflow in performing Recursion..
    func3();            // stack is also fixed-space..In stack we need not to allocate and deallocate memory..

    return 0;
}

//                                                        HEAP

int_32 main(){
    int a = 10;                     // stored in stack.. 
    int *p = new int();             // allocate memory in heap..
    *p = 10;                        // p -> is memory address in stack , where *p -> pointing the memory address of int in heap..
    delete(p);                      // In heap we need to allocate and deallocate memory..
                                    // which create "dangling pointer" in heap which is empty 
                                    // and it should be in heap that why we need to deallocate or delete it..
    p = new int[4];                 // p -> address of first item of array...and 
                                    // we can allocate the value to array during "runtime"..in heap.

    delete []p;                     // we can delete the block of array.
    p = NULL;                       // which stop pointing from stack to heap..

    return 0;                           
}

// heap -> is an free-space 
// In heap we need to allocate and deallocate memory..
// De-allocate is issues in server, because it will not terminate..