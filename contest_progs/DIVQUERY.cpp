#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <istream>
#include <iterator>
using namespace std;

int main()
{
int N,Q,i=0;
cin>>N>>Q;
vector<int> A(N);
while(i<N)cin>>A[i++];
while(Q--)
{
int L,R,K,count=0;
cin>>L>>R>>K;
for(int i=L-1;i<R;i++)
   if(A[i]%K==0)count++;
cout<<count<<'\n';   
}

return 0;
}