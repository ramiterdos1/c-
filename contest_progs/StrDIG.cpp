#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <istream>
#include <sstream>
#include <iterator>
using namespace std;

int p[100000];//substring table
void compute_prefix(const char * s)
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

}
int kmp_matcher(const char *s,const char *s1)
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
			++k;break;
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
cout<<"HERE BABES"<<k<<'\n';
//if(!k)printf("NOT FOUND ANY PATTERN\n");
return k;
}
string itos(long long i) // convert int to string
{
    stringstream s;
    s << i;
    return s.str();
}
int main()
{
long long i=1000000;
string s="";
for(long long j=1;j<=i;j++)
   s=s+itos(j);
cout<<s<<'\n';   
int t;
cin>>t;
while(t--)
{
 string sub;
 cin>>sub;
 compute_prefix(sub.c_str());
 if(kmp_matcher(s.c_str(),sub.c_str()))
 cout<<"YES\n";
 else cout<<"NO\n";
}   
}