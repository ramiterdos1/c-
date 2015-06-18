#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;
bool comp(string s, string t)
{
  int l1=s.length(),l2=t.length();
  if(l1>l2)
     return 0;
  else if(l2>l1)
         return 1;
       else {
		if(s>t)return 0;
		else return 1;
             }
}

int main() {
    int T=0;
    cin>>T;
    string st;
    cin>>st;
    int mismatch[5001],ct=0,j=st.size();
   // cout<<mismatch[1]<<'\n';
   // fill_n(mismatch,5,5);
   //  cout<<mismatch[1]<<'\n'<<'j'<<j<<'\n';
    vector<string> s(j*(j+1)/2);
    for(int i=0;i<j;i++)
    {
        for(int k=1;k<=j-(i?i:1);k++)
            s[ct++]=string(st,i,k);
    }
    //cout<<ct<<'\n';
    //while(ct--)cout<<s[ct]<<'\n';
    sort(s.begin(),s.end(),comp);
    ct=0;
    while(ct<((j*(j+1))>>1) )cout<<s[ct++]<<'\n';
    int mx_sz=(j*(j+1))>>1,mis=0;
    for(int i=0;i<mx_sz;i++)
     {
	
     }
    return 0;
}

