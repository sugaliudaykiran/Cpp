# include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cout << "Enter the Number : ";
    cin >> N;

    if (N % 2 == 0 && N % 3 == 0){
        cout << "N is divisble by 3 and 2 " << endl;
    }
    else if (N % 2 == 0){
        cout << "N is divisble by 2" << endl;
    }
    else if (N % 3 == 0){
        cout << "N is divisble by 3" << endl;
    }
    else{
        cout << "N is not divisble by 3 and 2" << endl;
    }
    return 0;

}