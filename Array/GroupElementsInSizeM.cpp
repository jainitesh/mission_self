/*
  Author : Nitesh Jain
  Date : 10/05/2017
  Link : http://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/ 
*/

#include<iostream>
#include<vector>

using namespace std;

bool duplicate (vector <int>& arr, int start, int end, int elem)
{
  while (start <= end)
  {
    if (arr[start] == elem)
     return true; 
    start++;
  }
  return false;
}

void GroupElements (vector<int>& arr, int m)
{
  for (int i = 0; i < arr.size(); i += m)
  {
    cout<<"loop"<<endl;
    for (int j = i+1 ; j < i+m && j < arr.size (); j++)
    {
      cout<<"loop1 "<<i<<endl;
      while (duplicate (arr, i, j-1, arr[j]))
      {
        int k = j + 1;
        while (arr[j] == arr[k] && k < arr.size())
          k++; 
        cout<<"swaping "<<arr[j]<<" "<<arr[k]<<endl;
        swap (arr[j], arr[k]);
      }
    }
  }
}

main ()
{
   vector <int> arr = {2,1,1,1,3,4,4,4,5};
   GroupElements (arr, 3);
   for (int i ; i < arr.size(); ++i)
     cout<<arr[i]<<endl;
}
