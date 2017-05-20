/*
  Author : Nitesh Jain
  Date : 20/05/2017
  Link : http://www.geeksforgeeks.org/find-the-minimum-distance-between-two-numbers/ 
*/

#include<iostream>
#include<vector>

using namespace std;

int MinDistance (vector<int>& arr, int x, int y)
{
   int prev;
   int minDist = 999999;
   int i = 0;
   for (; i < arr.size(); i++)
   {
     if (arr[i] == x || arr[i] == y)
     {
       prev = i;
       break;
     }
   }
   for (; i < arr.size(); i++)
   {
      if (arr[i] == x || arr[i] == y)
      {
        if (arr[i] != arr[prev])
          minDist = min(minDist, abs(i-prev));
        prev = i;
      }
   }
   return minDist;
}

main()
{
  vector<int> arr = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}; 
  cout<<MinDistance (arr, 3, 6)<<endl;
}
