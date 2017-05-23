/*
  Author : Nitesh Jain
  Date : 23/05/2017
  Link : 
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int Lcs(string arr1, string arr2)
{
  vector<vector<int>> lcs(arr1.size()+1, vector<int>(arr2.size()+1, 0));
  for (int i = 1 ; i <= arr1.size(); i++)
  {
    for (int j = 1; j <= arr2.size(); j++)
    {
       if (arr1[i-1] == arr2[j-1])
         lcs[i][j] = lcs[i-1][j-1] + 1; 
       else
         lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]); 
    }
  }
  return lcs[arr1.size()][arr2.size()];
}

main()
{
  string arr1 = "AGGTAB"; 
  string arr2 = "GXTXAYB";
  cout<<Lcs(arr1, arr2)<<endl;
}
