/*
  Author : Nitesh Jain
  Date : 15/05/2017
  Link : 
*/

#include<iostream>
#include<vector>

using namespace std;

void PrintIndexEqalNumber (vector<int>& arr)
{
   int maxLength = 0;
   int startIndex = -1;
   for (int i = 0; i < arr.size() -1; i++)
   {
     int sum = 0;
     (arr[i] == 0)?sum = -1:sum=1;
      for (int j = i+1; j < arr.size(); j++)
      {
          (arr[j] == 0)?sum +=-1:sum += 1;
          if (sum == 0 && maxLength < j-1+1)
          {
            maxLength = j-i+1;
            startIndex = i;
          }
      }
   }
   cout<<startIndex<<" to "<<startIndex + maxLength -1<<endl;
}

main()
{
  vector<int> arr = {1, 0, 0, 1, 0, 1, 1};
  PrintIndexEqalNumber (arr);
}
