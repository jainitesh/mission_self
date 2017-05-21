/*
  Author : Nitesh Jain
  Date : 20/05/2017
  Link : http://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/
*/

#include<iostream>
#include<vector>

using namespace std;

void PrintMinLenght (vector<int>& arr)
{
   int lIndex;
   int rIndex;
   int min,max;
   for (lIndex = 0; lIndex < arr.size() - 1; lIndex++)
   {
      if (arr[lIndex] > arr[lIndex+1])
         break;
   }

   for (rIndex = arr.size () - 1; rIndex > 1; --rIndex)
   {
      if (arr[rIndex] < arr[rIndex-1])
         break;
   }
   
   
   min = arr[lIndex];
   max = arr[rIndex];
   for (int i = lIndex + 1; i <= rIndex; i++)
   {
     if (arr[i] < min)
      min = arr[i];
     if (arr[i] > max)
      max = arr[i];
   } 

   for (int i = 0; i < lIndex; i++)
   {
     if (arr[i] > min)
     {
       lIndex = i;
       break;
     }
   }

   for (int i = arr.size () -1; i > rIndex; i--)
   {
     if (arr[i] < max)
     {
       rIndex = i;
       break;
     }
   }
   
   cout<<lIndex<<" "<<rIndex<<endl;
}

main()
{
  vector<int> arr = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
  PrintMinLenght (arr);
}
