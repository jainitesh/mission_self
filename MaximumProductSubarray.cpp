/*
  Author : Nitesh Jain
  Date : 19/05/2017
  Link : 
*/

#include<iostream>
#include<vector>

using namespace std;

int MaximumProduct (vector<int>& arr)
{
   int maxProd = 1;
   int max_end = 1; 
   int min_end = 1; 
   for (int i = 0 ; i < arr.size() ; i++)
   {
     if (arr[i] > 0)
     {
        max_end = max_end * arr[i];
        min_end = min (min_end*arr[i], 1);
     }
     else if (arr[i] == 0)
     {
       max_end = 1;
       min_end = 1;
     }
     else
     {
        int temp = max_end;
        max_end = max (min_end * arr[i], 1);
        min_end = temp * arr[i];
     }
     if (maxProd < max_end)
        maxProd = max_end; 
   }
   return maxProd;
}

main()
{
   vector<int> arr = {-6, -3, 8, -9, -1, -1, 3, 6, 9, 0, 3, -1}; 
   cout<<MaximumProduct(arr)<<endl;
}
