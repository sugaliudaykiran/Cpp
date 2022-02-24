# include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int a,b;
    cin >>a >>b;
    for(int start = a; start <= b; start ++){
        int i ;
        for (i = 2; i < start; i++){
            if (start % i == 0){
                break;
            }
        }
        if (i == start){
            cout << i << endl;
        }
    }
    return 0;
}