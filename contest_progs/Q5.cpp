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
  if(s.x<=t.x && s.y<=t.y)
     return 1;
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
long long min,max,tmp;
N=1;
min=(coordinates[1].x-coordinates[0].x)*(coordinates[1].x-coordinates[0].x)+(coordinates[1].y-coordinates[0].y)*(coordinates[1].y-coordinates[0].y);

cout<<'\n';
while(N<n-1)
{
 tmp=(coordinates[N+1].x-coordinates[N].x)*(coordinates[N+1].x-coordinates[N].x)+(coordinates[N+1].y-coordinates[N].y)*(coordinates[N+1].y-coordinates[N].y);
 if(tmp<min)min=tmp;
 N+=1;
 }
max=(coordinates[n-1].x-coordinates[0].x)*(coordinates[n-1].x-coordinates[0].x)+(coordinates[n-1].y-coordinates[0].y)*(coordinates[n-1].y-coordinates[0].y);

cout<<min<<' '<<max<<'\n';
return 0;
}