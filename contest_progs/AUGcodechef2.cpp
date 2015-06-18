#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <istream>
#include <iterator>
using namespace std;
int mod= 1000000007;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;char c;
		cin>>n>>m;
		int b[n+1][m+1];
		for(int i=0;i<n;i++)
		{for(int j=0;j<m;j++)
		{
			c=getchar();
			switch(c)
				{
					case 'E':b[i][j]=-1;
					case '.':b[i][j]=0;
					case 'L':b[i][j]=1; 
				} 
		}
		getchar();
	    }
		int ls[n],rs[n],ts[m];
		for(int i=n-1;i>=0;i--)
		{
			ls[i]=0,ts[i]=0;
			for(int j=0;j<m;j++)
				
		 }
	}
return 0;
}