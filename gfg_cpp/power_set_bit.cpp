// Power_set_using_Bit-wise-Operator..

#include<bits/stdc++.h> 
#include<cmath>
using namespace std;

void power_set_bit(string str){             // TC -> 0(2_power * N);
    
    int n = str.length();

    int power_upto = pow(2, n);

    for (int counter=0; counter<power_upto; counter++){
        
        for (int i=0; i<n; i++){
            
            if ((counter & (1 << i)) != 0){
                cout << str[i];
            }
        }
        cout << endl;
    }
}

int32_t main(){
    string str;
    cin >> str;

    power_set_bit(str);
    return 0;
}