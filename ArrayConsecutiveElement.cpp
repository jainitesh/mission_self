/*
   Author : Nitesh Jain
   Date : 08/05/2017
   Link : http://www.geeksforgeeks.org/check-if-array-elements-are-consecutive/ 
*/

#include<iostream>
#include <vector>

using namespace std;


bool CheckConsecutiveArray (vector<int>& arr)
{
   int min = 999999999;
   for (auto i : arr)
    if(i < min)
      min=i ;
   
   for (int i = 0 ; i < arr.size(); i++)
   {
      if ((abs(arr[i]) - min) >= arr.size())
        return false;
  
      if (arr[abs(arr[i])-min] < 0)
        return false;

      arr[abs(arr[i])-min] = -arr[abs(arr[i])-min];
   }
   return true;;
}

main()
{
   vector<int> a = {75,78,76,77,73,74};
   cout<<CheckConsecutiveArray (a)<<endl;
}
