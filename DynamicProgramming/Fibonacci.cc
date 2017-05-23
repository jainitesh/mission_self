/*
  Author : Nitesh Jain
  Date : 23/05/2017
  Link : 
*/

#include<iostream>
#include<vector>

using namespace std;

int Fibonacci (int n)
{
  vector<int> fib(n + 1, 0);
  
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i <= n ; i++)
    fib[i] = fib[i-1] + fib[i-2];
  return fib[n];
}

main()
{
  cout<<Fibonacci(40)<<endl;
}
