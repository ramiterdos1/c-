#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
int N=0;
cin>>N;
vector<int> ar(N+1);
ar.assign(N+1,0);// or also vector<int> ar(N,0);
int i=1;
while(i<=N)
{
cin>>ar[i];
i++;
}
/*to check
i=0;
while(i<=N)
{
cout<<ar[i]<<"-";
i++;
}
*/

int T=0;
cin>>T;
while(T--)
{
int l,r,prod,mod;
cin>>l>>r>>mod;
if(l==r)prod=0;
else {
prod=ar[l]%mod;
for(i=l+1;i<=r;i++)
{
  int temp=ar[i]%mod;
  prod=(prod*temp)%mod;  
}
}
cout<<prod<<'\n';
}
return 0;
}