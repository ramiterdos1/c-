#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;
template <class datatype>
class Set
{
  int CardinalNo;int type;
  struct Cartesian
  {
	  int x;int y;
  }
  struct List
  {
    datatype data;
    struct List *next;
  }*s;
  
   typedef struct Cartesian OrderSet;
   public:
    Set();
    Set(int);
   int getCardinalNo()
     { return CardinalNo;};
   void PowerSet();
   void CartesianProduct(Set A,Set B);
   void Union(Set A,Set B);
   void Intersection(Set A,Set B);
   void Difference( Set A, Set B);
   void push(datatype data);
   void Complement(Set U, Set A);
   void DisplaySet();
   int * Convert2Array(void);
   void CheckRelation();
   static void Enter(const char *,Set);
};
void Set::CheckRelation()
{
  char s[300];int *SetArray=Convert2Array(),c=CardinalNo;
  bool **Relation,flg=1;
  Relation=(bool **)malloc(c*sizeof(bool *));
  for(int i=0;i<c;i++)
      {Relation[i]=(bool *)malloc(c*sizeof(bool));
        for(int j=0;j<c;j++)Relation[i][j]=(bool)0;
       }
  cout<<"Enter the Relation below...."<<endl; 
  cin>>s;int i=2;
  while(s[i]) 
   {
     int x=0,y=0,j,k;
      while(s[i]!=')')
           { while(s[i]!=',')x=x*10+(s[i++]-'0');
             i+=1;
             while(s[i]!='}')y=y*10+(s[i++]-'0');  
            }
      for(j=0;j<c;j++)
         for(k=0;k<c;k++)
             if(SetArray[i]==x && SetArray[j]==y)
                {Relation[i][j]=1;k=c;j=c;}
   }
   for(i=0;i<c;i++)if(!Relation[i][i]){flg=0;cout<<"Relation Does Not Satisfy Reflexivity!"<<endl;break;}
    if(flg)
       {
          for( i=0;i<c;i++)
              for(int j=i+1;j<c;j++)
                  if(Relation[i][j]!=Relation[j][i])
                     {flg=0;cout<<"Relation is Reflexive but not Symmetric!"<<endl;i=c;j=c;}
           if(flg)
            {
               
               for( i=0;i<c;i++)
                 for(int j=0;j<c;j++)
                  for(int k=0;k<c;k++)if(!(Relation[i][j] && Relation[j][k] && Relation[i][k]))
                      { flg=0;
                        cout<<"Relation is Reflexive,Symmetric but not Transitive!"<<endl;
                        i=j=k=c;
                      } 
              if(flg){cout<<"Relation Entered is a Equivalence Relation!"<<endl;}

            }
       }     
}//end    
int * Set:: Convert2Array(void)
{
	int *a=(int *)malloc(CardinalNo*sizeof(int));
	 List *temp=new List[1];
	int i=0;
	for(temp=s;temp;temp=temp->next)
		a[i++]=temp->data;
	return a;	
}
void Set :: DisplaySet()
{
   if(CardinalNo!=0){
   cout<<"{";List *temp=new List[1];
   temp=A.s;
   for(int i=1;i<=A.CardinalNo;i++)
      { if(i!=A.CardinalNo)
          {if(A.type==0) cout<<temp->data<<",";
           else if(A.type==1)cout<<"("<<(temp->data.x)<<(temp->data.x)<<"),";
                else {temp->data.DisplaySet();cout<<",";}
           }
        else {if(A.type==0) cout<<temp->data<<"}";
               else if(A.type==1)cout<<"("<<(temp->data.x)<<(temp->data.x)<<")}";
                 else {temp->data.DisplaySet();cout<<"}";}
              }
               
        temp=temp->next;
      }
  // delete[] temp;
  } else { cout<< "{ }";}
}
void Set:: push(datatype d)
{
    List temp=new List[1];
    List Node=new List[1];
   temp=s;Node->data=d;Node->next=NULL;
   if(temp==NULL)
      s=Node;
   else {
          if((Node->data)<(temp->data))
             { 
                Node->next=s;
                CardinalNo++;
              }
           else{
                 while((temp->next)!=NULL)
                          {if((temp->next->data)>(Node->data)) 
                             {
                                Node->next=temp->next; 
                                temp->next=Node;
                                CardinalNo++;break;
                              } 
                            else if((temp->next->data)==(Node->data)) break;
                            temp=temp->next;
                           } 
                      if((temp->data)<(Node->data))
                          temp->next=Node;
                 }
          }
}
Set:: Set()
{
	CardinalNo =0;flag=0;
        s=(List *)malloc(sizeof(List));
}
Set:: Set(int f)
{
 CardinalNo =0;flag=f;
 s=(List *)malloc(sizeof(List));
 }  
void Set:: PowerSet()
{
   bool *b=(bool *)malloc((CardinalNo+1)*sizeof(char));
   int p=2,i=1;
   for(;i<=CardinalNo;p*=p,b[i++]=0);
   int *P=Convert2Array();
   cout<<"\t\t\tThe Power Set \n{{},";
   for(i=1;i<p,i++)
      { int j=1,n=i; 
        cout<<"{";
        while(n)
            { b[j++]=n%2; n/=2;};
        for(j=1;j<=CardinalNo;j++)
            if(b[j])cout<<P[j-1]<<" "; 
        cout<<"},";
       }
   cout<<"\b}"<<endl;
}

}
void Set:: CartesianProduct(Set A,Set B)
{
  
  CardinalNo=A.CardinalNo*B.CardinalNo;
  int *Aelem=A.Convert2Array();
  int *Belem=B.Convert2Array();
  for(int i=1;i<=A.CardinalNo;i++)
	  for(int j=1;j<=B.CardinalNo;j++)
	  {
		  
		  s->data.x=Aelem[i];C.s->data.y=Belem[j];
	  }
   
}
void Set:: Union(Set A,Set B)
{
   Set<int> smallerSet=new Set();
    smallerSet=(A.CardinalNo<B.CardinalNo)?A:B;
 for(int i=1;i<=smallerSet.CardinalNo;i++)
   { push(smallerSet.s->data);smallerSet.s=smallerSet.s->next;}
  smallerSet=(smallerSet==A)?B:A;
 for(int i=1;i<=smallerSet.CardinalNo;i++)
   { push(smallerSet.s->data);smallerSet.s=smallerSet.s->next;}
  
}
void Set:: Intersection(Set A,Set B)
{
   Set<int> smallerSet=new Set();
   smallerSet=(A.CardinalNo<B.CardinalNo)?A:B;
     
 for(int i=1;i<=smallerSet.CardinalNo;i++)
   {  int flag=0;Set<int> LargerSet=new Set();
       LargerSet=(smallerSet==A)?B:A;
      for(int j=1;j<=LargerSet.CardinalNo;i++)
          if(smallerSet.s->data==LargerSet.s->data)
             {flag=1;break;}
          else LargerSet.s=LargerSet.s->next;
      if(flag)
      push(smallerSet.s->data);
      smallerSet.s=smallerSet.s->next;
    }
  return C;
  
}
void Set:: Difference(Set A,Set B)
{
   
   Set<int> FirstSet=new Set();
   FirstSet=A;
     
 for(int i=1;i<=FirstSet.CardinalNo;i++)
   {  int flag=1;Set<int> _2ndSet=new Set();
      _2ndSet=B;
      for(int j=1;j<=_2ndSet.CardinalNo;i++)
          if(FirstSet.s->data==_2ndSet.s->data)
             {flag=0;break;}
          else _2ndSet.s=_2ndSet.s->next;
      if(flag)
      push(FirstSet.s->data);
      FirstSet.s=FirstSet.s->next;
    }
  
}
void Set:: Complement(Set U,Set A)
{
   
   Set<int> FirstSet=new Set();
       FirstSet=U;
     
 for(int i=1;i<=FirstSet.CardinalNo;i++)
   {  int flag=1;Set<int> _2ndSet=new Set();
      _2ndSet=A;
      for(int j=1;j<=_2ndSet.CardinalNo;i++)
          if(FirstSet.s->data==_2ndSet.s->data)
             {flag=0;break;}
          else _2ndSet.s=_2ndSet.s->next;
      if(flag)
      push(FirstSet.s->data);
      FirstSet.s=FirstSet.s->next;
    }
  
}
static void Set:: Enter(const char *s,Set a)
{
    int inp=0;
    printf("Enter the elements of the %s!\n",s);
    printf("Enter the elements:(Space Separate Them)");
            do
               { scanf("%d",inp);a.push(inp);
                }while((ch=getchar())!='\n');
}
int main()
{
   do{
      char ch=0;
      Set<int> U,A,B;
      Set::Enter("UNIVERSAL SET",U); 
      Set::Enter("SET A",A);
      Set::Enter("SET B",B); 
      printf("Displaying Set U\n");
      U.DisplaySet();
      printf("Displaying Set A\n");
      A.DisplaySet();
      printf("Displaying Set B\n");
      B.DisplaySet();
      do{
      printf("1.Find Complement\n2.Find Cartesian Product\n3.Find Union\n4.Find Intersection\n5.Find Difference\n6.Exit from this program\n7.Operate on new Sets\n8.Check a Relation\n9.See the Power Set\nEnter:");
      ch=getchar();printf("\n");
       switch(ch-'0')
        {
           case 1:printf("Press 1 to find complement of Set A\nPress 2 to find complement of Set B\nEnter :");
                  ch=getchar();printf("\n");
                  Set<int> C;
                   switch(ch-'0')
                      {
                         case 1:
                                C.Complement(U,A);
                                printf("Displaying ~A\n");
                                C.displaySet();cout<<endl;
                                break; 
                         case 2:C.Complement(U,B);
                                printf("Displaying ~B\n");
                                C.displaySet();cout<<endl;
                                break; 
                         default:ch='p';printf("\n\t\t\tInvalid Choice!\n");
                       }
                  break;
           case 2: Set<int> X,Y;Set<OrderSet> C=new Set(1);
                   printf("Enter First Set(choose between U,A,B):\n");
                   ch=getchar(); getchar(); 
                   if(ch=='U' ||ch=='u')X=U;
                   else if(ch=='A' || ch=='a')X=A;
                         else X=B;
                   printf("Enter Second Set(choose between U,A,B):\n");
                   ch=getchar(); getchar(); 
                   if(ch=='U' ||ch=='u')Y=U;
                   else if(ch=='A' || ch=='a')Y=A;
                         else Y=B;
                   C.CartesianProduct(X,Y);
                   printf("\t\t\t...Displaying the Cartesian Product!\n"); 
                   C.DisplaySet();cout<<endl;
                   break;
           case 3: Set<int> C;
                   C.Union(A,B);
                   printf("\t\t\t...Displaying the Union Set!\n"); 
                   C.DisplaySet();cout<<endl;
                   break;
           case 4: Set<int> C;
                   C.Intersection(A,B);
                   printf("\t\t\t...Displaying the Intersection Set!\n"); 
                   C.DisplaySet();cout<<endl;
                   break;
           case 5: Set<int> C;
                   C.Difference(A,B);
                   printf("\t\t\t...Displaying A-B!\n"); 
                   C.DisplaySet();cout<<endl;
                   C.Difference(B,A);
                   printf("\t\t\t...Displaying B-A!\n"); 
                   C.DisplaySet();cout<<endl;
                   break;
           case 6: printf("\t\t      TERMINATING PROGRAM....");
                   exit(0);
           case 7: cout<<"You will b asked for a new set of Values to the Sets u were operating on!"<<endl;
                   ch=0;break;
           case 9: cout<<"\t\tPower Set Of A will be Displayed...."<<endl; A.PowerSet();
                   cout<<"\t\tPower Set Of B will be Displayed...."<<endl; B.PowerSet(); 
                   break;
           case 8: cout<<"Enter the set on whom u wish to enter the relation.(A or B):";
                   cin>>ch;
                     if(ch=='A')A.CheckRelation();
                     else if(ch=='B')B.CheckRelation();
                          else{ cout<<"Wrong Choice... Defaultly the Universal Set is chosen!"<<endl;
                                U.CheckRelation();  }
                   ch='o';break; 
           default:printf("Wrong Choice\n");
         };
         }while(ch);
        }while(1);
} 
