# include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int pocketmoney = 1000;

    for (int day = 1; day <= 30; day++){
        if (day % 2 == 0){
            continue; // used for skip to  the Next iteration of loop;
        }
        
        if (pocketmoney == 0){
            break; // used for terminate the loop; 
        }
        cout << "we will go out..." << endl;
        pocketmoney = pocketmoney - 150;
    }
    return 0;

}