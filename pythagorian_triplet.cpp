#include<bits/stdc++.h>
#include<math.h>
using namespace std;

bool check(int x, int y, int z){
    int a = max(x, max(y, z));
    int b, c;

    if (a == x){
        b = y;
        c = z;
    }
    else if (a == y){
        b = z;
        c = x;
    }
    else{
        b = x;
        c = y;
    }
    if (pow(a, 2) == (pow(b, 2) + pow(c, 2))){ 
        // here we can use like ... -> (a*a == b*b + c*c)
        return true;
    }
    else{
        return false;
    }
}

int32_t main(){
    int x,y,z;
    cout << "x, y, z : ";
    cin >> x >> y >> z;

    if (check(x,y,z)){
        cout << "Pythagorian_Triple..." << endl;
    }
    else{
        cout << "Not a Pythagorian_Triple..." << endl;
    }

    return 0;
}