/*
  Author : Nitesh Jain
  Date : 23/05/2017
  Link : 
*/

#include<iostream>
#include<vector>

using namespace std;

int LongestIncreasingSubSeq (vector<int>& arr)
{
  vector<int> lis (arr.size(), 1);
  int max = -1;
  for (int i = 1 ; i < arr.size (); i++)
  {
     for (int j = 0; j < i; j++)
     {
       if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
          lis[i] = lis[j] + 1;
     }
     if (lis[i] > max)
       max = lis[i];
  }
  return max; 
}

main()
{
  vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
  cout<<LongestIncreasingSubSeq (arr)<<endl;
}
