/*
  Author : Nitesh Jain
  Date : 15/05/2017
  Link : 
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

int FindMaximumLen (vector<int>& arr)
{
  vector<int> sum(arr.size());
  map<int, int> m;
  
  int maxLen = 0;
  sum[0] = (arr[0] == 0)? -1 : 1;
  for (int i = 1; i < arr.size(); i++)
   sum[i] = sum[i-1] + (arr[i] == 0 ? -1 : 1);

  for (int i = 0 ; i <  arr.size(); i++)
  {
    if (sum[i] == 0)
      maxLen = max(maxLen, i+1);
    if (m.find(sum[i]) != m.end ())
       maxLen = max(maxLen, (i - m[sum[i]]));
    else
       m.insert (pair<int, int> (sum[i], i));
  }
  return maxLen;
}

main()
{
  vector<int> arr = {1, 0, 0, 1, 0, 1, 1};
  cout<<FindMaximumLen (arr)<<endl;
}
