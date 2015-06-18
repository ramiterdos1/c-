#include<stdio.h>
#include<stdlib.h>
int main()
{
char c1='0',c2='0';
int n=0;
while((c1=getchar())!='\n')
{
   n=(c2-'0')*10+(c1-'0');c2=c1;        
}
if(n%4 ==0) printf("4\n");
else printf("0\n");
return 0;
}
