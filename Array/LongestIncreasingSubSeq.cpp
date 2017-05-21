/*
  Author : Nitesh Jain
  Date : 11/05/2017
  Link : 
*/

#include<iostream>
#include<vector>

using namespace std;
void PrintLongestSubsequence(vector<int>& arr)
{
  vector<int> res (arr.size(), 1);
  for (int i = 1; i < arr.size(); i++)
  {
    int j = 0;
    while (j < i)
    {
      if (arr[j] < arr[i])
       res[i] = max (res[j] + 1, res[i]);
      j++;
    } 
  }
  cout<<res[res.size () -1]<<endl;
  return;
}

main()
{
  vector<int> arr = {3,4,-1,0,6,2,3};
  vector<int> arr1 = {10,22,9,33,21,50,41,60,80};
  vector<int> arr3 = {3,10,2,1,20};
  PrintLongestSubsequence(arr3);
}
