/*
  Author : Nitesh Jain
  Date : 08/05/2017
  Link : http://www.geeksforgeeks.org/check-given-array-contains-duplicate-elements-within-k-distance/
*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

bool CheckDuplicateElements(vector<int>& v, int k)
{
  set<int> s;
  for (int i = 0 ; i < v.size(); ++i)
  {
    if (s.count (v[i]) > 0)
      return false;

    s.insert(v[i]);
 
    if ((i-k) >= 0)
     s.erase(v[i-k]); 
  }
  return true;
}

main()
{
  vector<int> v = {1,2,3,4,1,2,3,4};
  cout<<CheckDuplicateElements(v, 4)<<endl;
}
