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

struct result
{
  int buy;
  int sell;
};

vector<result> MaxProfitMultiple(vector<int>& a)
{
   int count = 0;
   int i = 1;
   vector<result> res;
   result r;
   while (i < a.size())
   {
      while ((i < a.size()) && a[i-1] > a[i])
        i++;
     
      if (i == a.size ())
        break;
     
      r.buy = i;

      while ((i < a.size()) && a[i-1] < a[i])
        i++;
      
      r.sell= i;
      res.push_back(r);
   }
   return res;
}

main()
{
   vector<int> a = {100, 180, 260, 310, 40, 535, 695};
   cout<<MaxProfitOnce(a)<<endl;
   vector<result> res = MaxProfitMultiple(a);
   for (int i = 0; i < res.size(); i++)
     cout<<"Buy = "<<res[i].buy<<"th Day and Sell = "<<res[i].sell<<"th Day"<<endl;
}
