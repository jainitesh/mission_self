/*
  Author : Nitesh Jain
  Date : 10/05/2017
  Link : http://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/ 
*/

#include<iostream>
#include<vector>

using namespace std;

struct Pumps
{
  int petrol;
  int distance;
};

int printTour (vector<Pumps>&p)
{
  int start = 0;
  int end = 1;
  int curr_petrol = p[0].petrol - p[0].distance;
  
  while (start != end || curr_petrol < 0)
  {
    while (curr_petrol < 0 && start != end)
    {
      curr_petrol -= p[start].petrol - p[start].distance;
      start  = (start + 1)%p.size();  
    
      if (start == 0)
        return -1;
    }
    
    curr_petrol += p[end].petrol - p[end].distance;
    end = (end + 1)%p.size(); 
  }
}


main()
{
   vector<Pumps> p = {{6, 4}, {3, 6}, {7, 3}};
   cout<<printTour (p)<<endl;
}
