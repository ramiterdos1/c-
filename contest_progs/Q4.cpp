#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <istream>
#include <iterator>
using namespace std;

bool matches(string s,string sub_s)
{
int l=s.length(),m=sub_s.length();
bool t=true;
      
for(int i=0;i<l;i++)
    {
      if(sub_s[i%m]!=s[i])
      { t=false;break;
      } 
    }
return t;
}
int main()
{
int T=0;
string a,b;
int l1,l2;
cin>>T;
while(T--)
{
cin>>a>>b;
l1=a.length();l2=b.length();
if(l1>l2)
{
if(l1%l2==0)
   if(matches(a,b))cout<<"YES\n";
   else cout<<"NO\n";
else cout<<"NO\n";   
}
else if(l2>l1)
{
if(l2%l1==0)
   if(matches(b,a))cout<<"YES\n";
   else cout<<"NO\n";
else cout<<"NO\n";   
}
else {
if(a==b)cout<<"YES\n";
else cout<<"NO\n";
}

}
return 0;
}