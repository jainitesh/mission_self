/*
  Author : Nitesh Jain
  Date : 13/05/2017
  Link : http://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/ 
*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

int Partition (vector<int>&arr, int start, int end);

int FindKthSmallestElement (vector<int>&arr, int start, int end, int k)
{
  while (true)
  {
     int pi = Partition (arr, start, end);
     int length = pi-start + 1;
     if (length == k)
       return arr[pi];
     if (k < length)
       end = pi-1;
     else
     {
       start = pi + 1;
       k = k - length;
     }
  }
}

int Partition (vector<int>&arr, int start, int end)
{
  int pivot = arr[end];
  int i = start - 1;
  for (int j = start ; j <= end-1 ; j++) 
  {
     if (arr[j] <= pivot)
     {
        i++;
        swap (arr[i], arr[j]);
     }
  }
  ++i;
  swap (arr[i], arr[end]);
  return i;
}

main()
{
  vector<int> arr = {7, 10, 4, 3, 20, 15};
  int k = 1;
  cout<<FindKthSmallestElement (arr, 0, arr.size()-1, k)<<endl;
  //for (int i = 0; i < arr.size(); i++)
   // cout<<arr[i]<<endl;
}
