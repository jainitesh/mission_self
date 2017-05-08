/*
  Author : Nitesh Jain
  Date : 08/05/2017
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> AddTwoArrays(vector<int>&a, vector<int>& b)
{
   int l = max (a.size(), b.size());
   vector<int> result (l);

   int a_size = a.size()-1;
   int b_size = b.size()-1;
   
   int carry = 0;
   while (a_size >= 0 && b_size >= 0)
   {
      int sum = a[a_size--] + b[b_size--] + carry;
      result[--l] = sum%10;
      carry = sum/10;
   }

  while (a_size >= 0)
  {
    int sum = a[a_size--] + carry;
    result[--l] = sum%10;
    carry = sum/10;
  }
  while (b_size >= 0)
  {
    int sum = b[b_size--] + carry;
    result[--l] = sum%10;
    carry = sum/10;
  }
  if (carry > 0)
  {
    result.resize (result.size()+1);
    for (int i = result.size() - 1 ; i > 0; --i)
    {
      result[i] = result[i-1];
    }
    result[0] = carry;
  }
  return result;
}


main()
{
   vector<int> a;
   vector<int> b;
   for (int i = 0; i < 10; i++)
      a.push_back(9);
   for (int i = 0; i < 5; i++)
      b.push_back(9);
   vector<int> result = AddTwoArrays(a, b);
   for (int i = 0; i < result.size(); i++)
     cout<<result[i]<<" ";
   cout<<endl;
}
