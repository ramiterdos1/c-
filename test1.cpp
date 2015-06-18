#include <iostream>
#include <cmath>
using namespace std;
class test1
{ public :
 int n1,n2,n3;
 struct S
  {   int n1,n2;short n3:1;
      //struct S *nxt;
      void b(){cout<<"HI BICHI!\n";};
   } s1;
void bla(void);
//int main();
 test1()
{
cout<<"HI BICHI!\n";
} 
};//end of class

int  main()
 { 
   
   test1 t=test1();t.s1={2,53,12};
   
   cout<<sizeof(int)<<"and pointersize->"<<sizeof(void *);
   cout<<"\n"<<sizeof(t)<<" "<<t.s1.n3<<endl;
   int y=2;
   int &x=y;
   ++x;
   y=x+1;
   cout<<y<<x<<endl;
   y=(int)sqrt(x);
   cout<<y<<x<<endl;
  return 0;
  }//end of main()
