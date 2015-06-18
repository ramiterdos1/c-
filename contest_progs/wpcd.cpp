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

bool comp(int s, int t)
{
  if(s>t)return 1;
  return 0;   
}

int main()
{
int T=0;
cin>>T;
while(T--)
{
int N=0,n;double tot=0;
cin>>N;
vector <int> arr(N);n=N;
while(n--)cin>>arr[n];
sort(arr.begin(),arr.end(),comp);
for(int i=0;i<N-2;)
  {
    bool t=true;
    double s,x,y,z;
    s=(arr[i]+arr[i+1]+arr[i+2])/2.0;
    x=s-arr[i];
    y=s-arr[i+1];
    z=s-arr[i+2];
    if(s<=0||x<=0||y<=0||z<=0)
       t=false;
    if(t)
    {
      i+=3;double val=sqrt(s*x*y*z);
      //cout<<sqrt(s*x*y*z)<<'\n';
      tot+=val;
    }   
    else i++;
  }
  printf("%0.6f\n",tot);
}
return 0;
}