#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include<limits>
using namespace std;
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int i = 0;
struct hehe
{
int i;int b;
};
void sig_alarm_handler(int signal) {
    ++i;
    printf("%d\n", i);
    if(i < 10)
        alarm(1);
    else
        exit(0);
}

int main() {
cout<<"Largest int="<<numeric_limits<int>::max()<<'\n';
    hehe* i=new hehe;
    cout<<i->i<<','<<i->b<<'\n';
    //char c='o';
    i->i=int('o');cout<<i<<','<<i->i<<'\n';
    signal(SIGALRM, sig_alarm_handler);
    alarm(1);
    int x;
    scanf(" %d",&x);
    return 0;
}
