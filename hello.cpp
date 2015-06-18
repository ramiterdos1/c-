#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int primes[]={0,2,3,5,7,11,13,17,19,23,29,31};

int size=12;
struct rokda
{
int m;
double r;
long long c;
int p_rep[12];
};
void setrep(rokda *r)
{
int n=r->m,i=1;
while(i<size)
{
int countr=0;
l1:
if(!(n%primes[i]))
{
n=n/primes[i];
countr++;
goto l1;
}
else
{
r->p_rep[i]=countr;
i++;
}
}
}
long long Lcm(int n,vector<rokda> r)
{
 vector<int> lcm(size);
  lcm.assign(size,0);
long long lcm_val=1;
 for(int i=1;i<size;i++)
 {
   int max=0;
   for(int j=1;j<=n;j++)
   {
      if(max<r[j].p_rep[i])max=r[j].p_rep[i];
   }
   lcm[i]=max;
   for(int j=1;j<=max;j++)
    lcm_val*=primes[i];
 }

/*for displaying
cout<<"LCM VALUE\n";
for( int i=1;i<size;i++)
{
   cout<<primes[i]<<'^'<<lcm[i]<<((i==size-1)?'\n':'*');
}
cout<<"lcm_val->"<<lcm_val<<'\n';

*/

return lcm_val;
}
int main()
{
int T=0;
cin>>T;
while(T--)
{
int U,N,n;double D;
cin>>D>>U>>N;
vector<rokda> r(N+1);
vector<double> tot_cost(N+1);
n=1;
while(n<=N)
{
cin>>r[n].m>>r[n].r>>r[n].c;
setrep(&r[n]);
n++;
}
long long lcm=Lcm(N,r);
//cout<<"lcm->"<<lcm<<'\n';
double min=U*D*lcm;
tot_cost[0]=min;int pos=0;
for(int i=1;i<=N;i++)
   {
      int x=(lcm/r[i].m);
      tot_cost[i]=x*r[i].c+lcm*U*r[i].r;
      if(min>tot_cost[i])
      {
        min=tot_cost[i];
        pos=i;
      }
   }
/*for(int i=0;i<=N;i++)
   cout<<i<<'.'<<tot_cost[i]<<(i==N?'\n':' ');  */ 
 cout<<pos<<'\n';  
}
return 0;

}