/*
  Author : Nitesh Jain
  Date : 08/05/2017
  Link : http://www.geeksforgeeks.org/find-the-maximum-repeating-number-in-ok-time/ 
*/

#include<iostream>
#include<vector>

using namespace std;

int MaximumReaptingNumber (vector<int>& arr, int k)
{
  int max = 0;
  int index = -1;
  for (int i = 0; i < arr.size(); i++)
  {
     arr[arr[i]%k] += k;
     if (max < arr[arr[i]%k])
     {
        max = arr[arr[i]%k];
        index = arr[i]%k;
     }
  }
  return index;
}

main()
{
  vector<int> arr = {2, 3, 3, 5, 3, 4, 1, 7};
  cout<<MaximumReaptingNumber (arr, 8)<<endl;
}
