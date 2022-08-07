/*

    Given a stack with push(), pop(), empty() operations, delete the middle of the stack
     without using any additional data structure.
        Middle: ceil((size_of_stack+1)/2) (1-based index)

        Input: 
            Stack = {1, 2, 3, 4, 5}
            Output:
                ModifiedStack = {1, 2, 4, 5}
            Explanation:
                As the number of elements is 5 , 
                hence the middle element will be the 3rd
                element which is deleted
*/ 

#include<bits/stdc++.h>
using namespace std;

void deleteMid(stack<int>&s, int sizeOfStack, int index = 0)
    {
        if (index == sizeOfStack || s.empty())
                {
                    return;
                }
                
                int x = s.top();
                s.pop();
                deleteMid(s, sizeOfStack, index+1);
                
                if (index != sizeOfStack/2)
                {
                    s.push(x);
                }
    }



void deleteMid2(stack<int>&s, int sizeOfStack, int index = 0)
    {
        // code here.. 
        if (index == sizeOfStack/2)
        {
            s.pop();
            return;
        }
        
        int x = s.top();
        s.pop();
        deleteMid(s, sizeOfStack, index+1);
        
        s.push(x);
    }

int32_t main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> s;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            s.push(x);    
        }
        
        deleteMid(s, sizeOfStack);

        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }

    }
    return 0;
}
