#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <istream>
#include <iterator>
using namespace std;
#include <string.h>
#define Size 1000000+7
#define Sz   (1000000>>1) 
#define Min(a,b) a<b?a:b 
#define Max(a,b) a>b?a:b
extern void* memset(void *, int, size_t);
struct pair{
int i,j;
};
int main()
{
int T,n;
//int arr[Size];
cin>>T;
while(T--)
{
    int num=0;
    //memset(arr,0,Size);
   vector <int> arr(Size);
   cin>>n;
   while(n--)
      {
        cin>>num;
        arr[num]++;
      }
   num=0;
   for(int i=1;i<=Sz+1;i++)
      {
      	 if(arr[i])
      	   if(arr[i<<1]){num+=Min(arr[i],arr[i<<1]);
      	   arr[i<<1]=Max(arr[i<<1]-arr[i],0);}
      }   
   cout<<num<<'\n';   
}
return 0;
}