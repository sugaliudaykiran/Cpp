#include<bits/stdc++.h>
#include<cstdlib>
#include<ctime>
using namespace std;

int32_t main()
{

    for (int i=0; i<5; i++)
    {
        cout << rand() << " "; // 0 to RAND_MAX (minmunm range 32767)..
    }cout << "\n";


    for (int i=0; i<5; i++)
    {
        cout << rand() % 100 << " "; // In this case the number are be same..
    }cout << "\n";  //  To avoid we need to use seed.



    // srand(unsigned int);
    // time_t time(time_t *t);      If (*t) points to NULL then it take current time..
    srand(time(NULL));
    for (int i=0; i<5; i++)
    {
        cout << rand()%10 << " ";
    }cout << "\n";  // This function uses Linear Congreential generator..
            //  Xn-1 = (aXn + b) % m  => where next random is generated using previous random number..


    int low = 10, high = 100; // a range random numbers..
    int range = high - low +1;
    for (int i=0; i<7; i++)
    {
        cout << (rand() % range) + low << " ";
    }cout << "\n";


    return 0;
}