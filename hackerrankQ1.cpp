#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <istream>
#include <iterator>
using namespace std;
//std::ios_base::sync_with_stdio(false);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
   /* string s[1000000];
    int i=0,j=0;s[0]="";
    istream_iterator<string> is(cin);
    while(s[i][0]!=EOF){cin>>s[i++];
	printf("%s\n",s[}
    j=i-1;*/

    istream_iterator<string> in(cin),eos;
    vector<string> s(in,eos);
    int j=s.size(),i=0;
    cout<<'j'<<'='<<j<<'\n';
   // cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<"\n"; 
    reverse(s.begin(),s.end());i=j;j=-1;
   // cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<"\n"; 
    while((++j)<=i-1)
    { s[j].assign(s[j].rbegin(),s[j].rend());
    }
    j=0;
    while(j<=i-1)
        cout<<s[j++]<<'\n';
    return 0;
}
