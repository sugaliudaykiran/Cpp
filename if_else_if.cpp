#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    char button;
    cout << "Click the Button : ";
    cin >> button;

    if (button == 'A'){
        cout << "Hello" << endl;
    }
    else if (button == 'B'){
        cout << "Namaste" << endl;
    }
    else if (button == 'C'){
        cout << "Hola" << endl;
    }
    else if (button == 'D'){
        cout << "Ciao" << endl;
    }
    else {
        cout << "Still learning..." << endl;
    }
    return 0;
}