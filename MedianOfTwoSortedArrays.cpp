/*
  Author : Nitesh Jain
  Date : 14/05/2017
  Link : 
*/

#include<iostream>
#include<vector>

using namespace std;

/*int Median (vector<int>&arr1, vector<int>&arr2, int start1, int end1, int start2, int end2)
{
  int l1 = start1-end1 + 1;
  int l2 = start2-end2 + 1;
  if (l1 + l2 == 2)
    return (arr1[l1] + arr2[l2])/2;
  
  int m1;
  int m2;
  if ((start1 + end1 + 1)%2 != 0)
    m1 = arr1[(start1+end1 + 1)/2];
  else
    m1 = (arr1[(start1+end1 + 1)/2] + arr1[(start1+end1 + 1)/2  - 1])/2;
  if ((start2 + end2 + 1)%2 != 0)
    m2 = arr2[(start2+end2 + 1)/2];
  else
    m2 = (arr2[(start2+end2 + 1)/2] + arr1[(start2+end2 + 1)/2 -1])/2;

  cout<<m1<<" "<<m2<<endl;
  if (m1 == m2)
    return m1;

  if (m1 <  m2)
  {
    int a1_start = (start1+end1 + 1)/2;
    int a2_end = (start2 + end2 + 1)/2;
    if ((start1 + end1 + 1)%2 == 0)
      a1_start -= 1;
    if ((start2 + end2 + 1)%2 == 0)
      a2_end -= 1;
     return Median (arr1, arr2, a1_start, end1, start2, a2_end);
  }
  else
  {
    int a1_end = (start1+end1)/2;
    int a2_start = (start2 + end2)/2;
    if ((start1 + end1)%2 == 0)
      a1_end -= 1;
    if ((start2 + end2)%2 == 0)
      a2_start -= 1;
     return Median (arr1, arr2, start1, a1_end, a2_start, end2);
  }
}*/

int Median (vector<int>&arr1, vector<int>&arr2, int astart, int aend, int bstart, int bend)
{
  int len = (aend - astart) + 1;
  if (len == 1)
    return (arr1[0] + arr2[0])/2;
  
  if (len == 2)
    return (max (arr1[astart], arr2[bstart] ) + min(arr1[aend] , arr2[bend]))/2;

  int mid1, mid2;
  if (len % 2 == 0)
  {
    mid1 = (arr1[(astart + aend)/2] + arr1[(astart + aend)/2 +1])/2;
    mid2 = (arr2[(bstart + bend)/2] + arr2[(bstart + bend)/2 +1])/2;
  }
  else
  {
    mid1 = arr1[(astart + aend)/2] ;
    mid2 = arr2[(bstart + bend)/2] ;
  }

  if (mid1 == mid2)
    return mid1;

  if (mid1 < mid2)
  {
    if (len % 2 == 0)
      return Median (arr1, arr2, (astart + aend)/2 , aend, bstart, (bstart + bend)/2 + 1);
    else
      return Median (arr1, arr2, (astart + aend)/2, aend, bstart, (bstart + bend)/2);
  }
  else
  {
    if (len % 2 == 0)
      return Median (arr1, arr2, astart , (astart + aend)/2 + 1, (bstart + bend)/2, bend);
    else
      return Median (arr1, arr2, astart , (astart + aend)/2, (bstart + bend)/2, bend);
  }
}

main()
{
  //vector<int> arr1 = {2,8,9,15,20};
  //vector<int> arr1 = {1, 12, 15, 26, 38};
  //vector<int> arr2 = {2, 13, 17, 30, 45};
  vector<int> arr1 =  {1, 2, 3, 6};
  vector<int> arr2 = {4, 6, 8, 10};
  cout<<Median (arr1, arr2, 0, arr1.size()-1, 0, arr2.size()-1)<<endl;
}
