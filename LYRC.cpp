#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int p[5000];//substring table
void compute_prefix(char * s)
{
int j=0,i=2,len=strlen(s);
memset(p,5000,0);
p[0]=-1;p[1]=0;
while(i<len)
{
  if(s[i-1]==s[j])
     {j++;p[i]=j;i++;
       }
  else {if(j){j=p[j];}
        else {
        		p[i++]=0;
              }
        }
    //p[i]=j;
}

/*displaying 
i=0;
while(i<len)
  printf("%5c",s[i++]);

printf("\n");
i=0;
while(i<len)
  printf("%5d",p[i++]);
printf("\n");

*/
//returning
//return p;

}
//s-string to search,s1-substring
int kmp_matcher(char *s,char *s1)
{

int i=0,j=0,m=strlen(s1)-1,k=0,len=strlen(s);
if(m)
{
while(j+i<len)
{
	if(s1[j]==s[j+i])
	{
		if(j==m)
		{//matched phase
			//printf("Pattern exists with shift %d. Count=%d\n",i,++k);
			//printf("%s\n",s);printf("%*c%*c\n",i+1,'^',m,'^');
			//j,i
			++k;
			i=i+m-p[j];
	        j=p[j];
		}
		else {j++;//Matching phase
		     } 
	}
	else 
	{
	   //not-matched phase
	   i=i+j-p[j];
	   j=j>0?p[j]:0;
	}	
}
}
else
{
j=-1;
 while((++j)<len)if(s[j]==s1[0])++k;
}
//if(!k)printf("NOT FOUND ANY PATTERN\n");
return k;
}
struct s{
char x[5000];
};
int main()
{
int W,N,i=1;
cin>>W;
vector<s> substrings(W+1);
while(i<=W)
{
scanf("%s",substrings[i++].x);
}
cin>>N;
i=1;
vector<s> Lyrics(N+1);
while(i<=N)
  scanf("%s",Lyrics[i++].x);
for(i=1;i<=W;i++)
   {
      int count=0;
      if(strlen(substrings[i].x)-1)compute_prefix(substrings[i].x);
      for(int j=1;j<=N;j++)
          count+=kmp_matcher(Lyrics[j].x,substrings[i].x);
      cout<<count<<'\n';
    }      
return 0;
}