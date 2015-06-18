#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
using namespace std;
extern int __getchar_unlocked();
extern int __putchar_unlocked(int c);
bool flag=1;
inline int inp()
{
int noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
if(flag && (noRead<0 || noRead>9))flag=0;
return noRead;
}

int main()
{
int sud[81];
for( int i=0;i<81;i++)sud[i]=0;
L1:cout<<(flag?"":"Please Re-")<<"Enter Sudoku\n";
for(int i=0;i<81;i++)sud[i]=inp();
if(!flag)goto L1;

return 0;
}
