#include <cstdio>
char s[]={' '};
extern int __getchar_unlocked();
extern int __putchar_unlocked(int c);
inline long inp()
{
long noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
}
int main()
{
#if defined(__unix__)||defined(__APPLE__)
//s={'a'};
printf("%s\n","app");

#endif
#if defined(__linux__)
//s={'l'};
printf("%s\n","linu");
#endif
long a,b;
char c;
L1:printf("Do you want to enter some numbers?\n");
   c=getchar_unlocked();
   if(c=='Y' || c=='y')
	{
	  printf("Enter the numbers!!\n");
	  a=inp();
	  b=inp();
	  printf("a=%ld,b=%ld\n",a,b);
	  a<b?:a^=b^=a^=b;
	  printf("a=%ld,b=%ld\n",a,b);
	  goto L1;
 	}
}
