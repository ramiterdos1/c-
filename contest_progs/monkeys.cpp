#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <istream>
#include <iterator>
using namespace std;
double mid=0;
bool comp(int a, int b)
{
if(abs(mid-a)<abs(mid-b))
return 1;
return 0;
}
int main()
{
int M,Z,N,r=0;
cin>>N;
while(N--)
{
cin>>M>>Z;
r=0;
vector<int> releases(Z);
while(r<Z)cin>>releases[r++];
mid=(M+1)/2.0;
sort(releases.begin(),releases.end(),comp);
r=0;
/*cout<<'\n';
while(r<Z)cout<<releases[r++];
cout<<'\n';*/
vector<int> arr(M);
//fill_n(arr.begin(),M,1);
int ct=0;
for(int i=0;i<Z;i++)
   {
      int j=0,pos=releases[i]-1;
      arr[pos]=1;
      if(pos>0)
      { j=pos-1;
      //towards 0
      while(j>=0 && !arr[j]){ct+=1;j-=1;}
      }
      if(pos<M-1)
      {
      j=pos+1;
      //towards M
      while(j<M && !arr[j]){ct+=1;j+=1;}
      }
   }
   cout<<ct<<'\n';

}
return 0;
}