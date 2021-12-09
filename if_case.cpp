# include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int saving;
    cin >> saving;

    if (saving > 5000){
        if (saving > 8000){
            cout << "Santhosh will take Roadtrip" << endl;
        }
        else{
            cout << "Santhosh will take Shopping" << endl;
        }

    }
    else if (saving > 2000) {
        cout << "hemanth"<<endl;
    }
    else{
        cout << "Solo" << endl;
    }
    return 0;
    
}