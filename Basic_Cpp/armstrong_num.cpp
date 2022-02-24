#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int32_t main(){
    int N;
    cout << "N : ";
    cin >> N;
    int sum = 0;
    int originalNum = N;
    

    while(N > 0){
        int lastnum = N % 10;
        sum += pow(lastnum, 3);
        N = N / 10;
    }
    if (sum == originalNum){
        cout << "Given N is an Armstrong_number."<< endl;
    }
    else{
        cout << "Given N is not an Armstrong_number." << endl;
    }

    return 0;
}