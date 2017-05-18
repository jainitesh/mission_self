/*
  Author : Nitesh Jain
  Date : 18/05/2017
  Link : http://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/ 
*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

int FindMaximumDiff (vector<int>& arr)
{
  vector<int> LMin (arr.size());
  vector<int> LMax (arr.size());

  LMin[0] = arr[0];
  for (int i = 1; i < arr.size(); i++)
    LMin[i] = min(LMin[i-1], arr[i]);

  LMax[arr.size() -1] = arr[arr.size ()-1];
  for (int i = arr.size() - 2; i >=0 ; --i)
    LMax[i] = max(LMax[i+1], arr[i]);

  int i = 0, j = 0;
  int maxDiff = 0;
  while (i < arr.size () && j < arr.size ())
  {
    if (LMin[i] < LMax[j])
    {
      maxDiff = max (maxDiff, j -i);
      j += 1;
    }
    else
      i += 1;
  }
  return maxDiff;
}

main()
{
  vector<int> arr = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
  cout<<FindMaximumDiff (arr)<<endl;
}
