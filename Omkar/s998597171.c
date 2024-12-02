#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
 
 int n;
 cin>>n;
 int m;
 cin>>m;
 if(m>=n)
  cout<<"unsafe";
else
  cout<<"safe";
  return 0; 
}