/*
  Author : Nitesh Jain
  Date : 18/05/2017
  Link : http://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/ 
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> SlidingWindowMaximum (vector<int>& arr, int k)
{
  vector<int> res;

  int m = -9999999;
  int i = 0;
  for (; i < k; i++)
    m = max (m, arr[i]); 
  
   res.push_back (m);
   for (; i < arr.size(); i++)
   {
     if (m != arr[i-k]  && m > arr[i])
       res.push_back(m);
     else if (m < arr[i])
     {
       res.push_back(arr[i]);
       m = arr[i];
     }
     else
     {
        m = -99999;
        for (int j = i-k+1; j <=i; j++)
	  m = max (m, arr[j]); 
       res.push_back(m);
     }
   }
   return res; 
}

main()
{
  vector<int> arr = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
  vector<int> res = SlidingWindowMaximum (arr, 4);
   for (int i = 0; i < res.size(); i++)
    cout<<res[i]<<" ";
   cout<<endl;
}
