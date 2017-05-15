/*
  Author : Nitesh Jain
  Date : 14/05/2017
  Link : 
*/

#include<iostream>
#include<vector>

using namespace std;

void findGreaterElement(vector<int>&arr, vector<int>&res)
{
  int num = arr[0];
  int j = 0;
  for (int i = 1; i < arr.size(); i++)
  {
    if (arr[i] > num)
    {
      num = arr[i];
      while (j != i)
      {
       res.push_back(num);
       j++;
      }
    }
  }
  while (j != arr.size())
  {
    res.push_back(-1);
    j++;
  }
}

main()
{
   vector<int> arr  = {4,2,-8,6,0,-3,-1,1,9}; 
   vector<int>res;
   findGreaterElement (arr, res);
   for (int i = 0 ; i < res.size(); i++)
     cout<<res[i]<<endl;
}
