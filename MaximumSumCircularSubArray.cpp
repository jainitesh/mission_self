/*
  Author : Nitesh Jain
  Date : 11/05/2017
  Link : http://www.geeksforgeeks.org/maximum-contiguous-circular-sum/
*/

#include<iostream>
#include<vector>

using namespace std;
int kadan (vector<int>& arr)
{
  int max = 0;
  int max_so_far = 0;
  for (int i = 0 ; i < arr.size (); ++i)
  {
    max_so_far += arr[i];
    if (max_so_far < 0)
      max_so_far = 0;
    if (max <  max_so_far)
     max = max_so_far; 
  }
  return max;
}

int MaximumSumCircular (vector<int>& arr)
{
  int max_kadan = kadan(arr);
  int max_circular = 0;
  for (int i = 0; i < arr.size(); ++i)
  {
    max_circular += arr[i];
    arr[i] = -arr[i];
  }
  max_circular += kadan(arr);
  return (max_kadan > max_circular)?max_kadan:max_circular;
}

main()
{
  vector<int> arr = {11, 10, -20, 5, -3, -5, 8, -13, 10};
  cout<<MaximumSumCircular (arr)<<endl;
}
