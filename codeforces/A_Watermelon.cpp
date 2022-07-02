#include<bits/stdc++.h>
using namespace std;

string helper(int w)
{
  if ((w-2) % 2 == 0 and (w-2) > 0)   //  It should be divide into two halves and halves should be an even numbers..
  {
    return "YES";
  }
  else
  {
    return "NO";
  }
}

int32_t main()
{

  int w;
  cin >> w;
  
  cout << helper(w) << "\n";
  return 0;
}