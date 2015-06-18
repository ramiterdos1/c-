#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <istream>
#include <iterator>
using namespace std;
struct pr{
int x,y;
};

bool comp(pr s, pr t)
{
  if(s.x<t.x)
     return 1;
  else if(s.x==t.x)if(s.y>=t.y)return 1;   
  return 0;   
}

int main()
{
int n=0;
cin>>n;
int N=n;
vector<pr> coordinates(n);
while(N--)
{
 cin>>coordinates[N].x>>coordinates[N].y;
}
sort(coordinates.begin(),coordinates.end(),comp);
cout<<'\n';
N=0;
while(N<n)
{
 cout<<coordinates[N].x<<' '<<coordinates[N].y<<'\n'; 
 N+=1;
 }
return 0;
}