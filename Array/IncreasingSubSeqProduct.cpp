/*
  Author : Nitesh Jain
  Date : 11/05/2017
  Link : http://www.geeksforgeeks.org/increasingsubs-equence-of-length-three-with-maximum-product/
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> GetMaxProduct(vector<int>& arr)
{
  int max_prod = 1;
  vector<int> res(3);
  for (int i = 1; i < arr.size(); i++)
  {
     int LSM = -1;
     int RSM = -1; 
     for (int j = 0; j < i; j++)
     {
        if (arr[j] < arr[i] && LSM < arr[j])
          LSM = arr[j];
     }
     for (int j = i + 1; j < arr.size(); j++)
     {
	if (arr[j] > arr[i] && RSM < arr[j])
	  RSM = arr[j];
     }
     
     if (max_prod < (LSM * arr[i] * RSM))
     {
        max_prod = LSM * arr[i] * RSM;
        res[0] = LSM;
        res[1] = arr[i];
        res[2] = RSM;
     }
  }
  return res;
}

main()
{
  //vector<int> arr = {6,7,8,1,2,3,9,10};
  vector<int> arr = {9,8,7,6,5,4,3,2,1};
  vector<int> res = GetMaxProduct (arr);
  for (int i = 0 ; i < res.size(); i++)
    cout<<res[i]<<" ";
  cout<<endl;
}
