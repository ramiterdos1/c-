#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <istream>
#include <iterator>
using namespace std;
long long gcd(long long a,long long b)
{
    if(a<b)return gcd(b,a);
    else {
        if(b==0)return a;
        else return gcd(b,a%b);
    }
}

int main()
{
    int T=0;
    cin>>T;
    while(T--)
        {
            long long n=0;
            cin>>n;
            long long t=n>>1;
            t=t+1;
        l1:t=(n%2)?t-1:t-2;
                    if(gcd(n,t)==1)
                        cout<<t<<'\n';
                    else goto l1;
                
            
        }
return 0;
}