# include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int x,y,z;
    cin >> x>> y>> z;
    if (x > y && x > z){
        cout << "first is Largest Number.." << endl;
    }
    else if (y > x && y > z){
        cout << "secound is Largest Number.. " << endl;
    }
    else{
        cout << "third is Largest Number.." << endl;
    }
    return 0;
}