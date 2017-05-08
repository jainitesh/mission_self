/*
   Author : Nitesh Jain
   Date : 08/05/2017
   Link : http://www.geeksforgeeks.org/stock-buy-sell/
*/

#include<iostream>
#include <vector>

using namespace std;
int MaxProfitOnce(vector<int>& a)
{
  int profit = 0;
  for (int i = 1; i < a.size (); ++i)
  {
    int diff = abs(a[i] - a[i-1]);
    (diff > profit)? profit = diff : profit += diff; 
  }
  return profit;
}

int MaxProfitMultiple(vector<int>& a)
{
  int profit = 0;
  for (int i = 1; i < a.size (); ++i)
  {
    int diff = abs(a[i] - a[i-1]);
    (diff > profit)? profit = diff : profit += diff; 
  }
  return profit;
}

main()
{
   vector<int> a = {100, 180, 260, 310, 40, 535, 695};
   cout<<MaxProfitOnce(a)<<endl;
}
