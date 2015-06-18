#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <istream>
#include <iterator>
using namespace std;

struct is_dig
{
bool d[10];
};
is_dig getdig(long long n)
{
is_dig s;
for(int i=0;i<=9;i++)
   s.d[i]=0;
 while(n>0)
 {
   int rem=n%10;
   n/=10;
   s.d[rem]=1;
 }  
 return s;
}
bool check(is_dig a,is_dig b)
{
bool ans=false;
for(int i=0;i<=9;i++)
   if(a.d[i] && b.d[i])
      {
        ans=true; break;
      }
      return ans;
}
int main()
{
int T=0;
cin>>T;
while(T--)
{
int n=0,i=0;
cin>>n;
vector<is_dig> arr(n);
long long num;
while(i<n)
{
cin>>num;
arr[i++]=getdig(num);
}
int ct=0;
for( i=0;i<n-1;i++)
   for(int j=i+1;j<n;j++)
       if(check(arr[i],arr[j]))ct++;
 cout<<ct<<'\n';      
}
return 0;
}