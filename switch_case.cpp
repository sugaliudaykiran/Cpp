#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    char Button;
    cout << "Click the button : ";
    cin >> Button;

    switch(Button){
        case 'A' :
            cout << "Hello" << endl;
            break;

        case 'B' :
            cout << "Namaste" << endl;
            break;

        case 'C' :
            cout << "Salut" << endl;
            break;
            
        case 'D' :
            cout << "Hola" << endl;
            break;

        case 'E' :
            cout << "Ciao" << endl;
            break;

        default :
            cout << "Learning more..." << endl;
            break;
    }
    return 0;
}