//#include <sys\type.h>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
class K_means{
// clustering m-tuple data
int no_of_Tuples,m,partitions,*tuple;
int *counter;
public:
    K_means(int,int,int,int);
    int ReadFirstLine(FILE *);//m
    void ReadFile(FILE *,int &,int &);//no_of_Tuples,partitions
    void Read_Tuples(FILE *, K_means[] );
    void WriteFiles(K_means[]);
    int Distance(int *, int *);//2 tuples
    //more functions  
    void initialize(int *,int );
    K_means find_mean(K_means[],int i , int counter);
    int equals( K_means *,K_means *); 
	int Tuple_close2_partition( K_means &, K_means[]);
 };
K_means:: K_means(int a,int b,int c,int flag)
{
	m=a;
   no_of_Tuples=b;
   partitions=c;
	if(flag)
	{
      tuple=new int[m];initialize(tuple,m);
   	}else{
		   	 counter=new int[c+1];
			 initialize(counter,c+1);
	}
}
void K_means:: initialize(int *ptr_array,int size)
{
   for(int i=0;i<size;i++)*(ptr_array+i)=0; 
 }
int K_means:: ReadFirstLine(FILE *f)
  {
	  char ch=0;int c=0;
	  while((ch=getc(f))!='\n')
	    if(ch>='0' && ch<='9')c++;
	 return c;
  }
 void K_means:: ReadFile(FILE *f,int & noT,int &P)  
 {
	 int ch=0,ch1=0;
	 while((ch=getc(f)))
		 if(ch=='\n')noT++;
		 else if(ch>='A'&& ch<='Z' && ch!=ch1)
		 {ch1=ch; P++;}
	noT++;	 //if the last line doesnt contain an enter
 }
 void K_means:: Read_Tuples(FILE *f, K_means k[] )
 {
	 int i=0,j=0;char ch=0;
	 while((ch=getc(f)))
	 {
	  if(ch>='0' && ch<='9')k[i].tuple[j++]=ch-'0';
	     if(j==m){ while(ch!=EOF || ch!='\n')  ch=getc(f);
		           j=0;i++;
		          }
	 }
	 cout<<i<<" "<<no_of_Tuples<<endl;
 }
 int K_means:: equals( K_means *k1,K_means *k2)
 {
	int flag=1;
	for(int i=1;i<partitions+1;i++)
           for(int j=0;j<m;j++)
		 if(k1[i].tuple[j]!=k2[i].tuple[j]){flag=0;break;}
	return flag;	 
 }
 int K_means:: Distance(int *k1, int *k2)
 {
	 int d=0,i=0;
	 for(;i<m;i++)
		 d+=(k1[i]-k2[i])*(k1[i]-k2[i]);
	return d;	 	 
 }
 void K_means:: WriteFiles(K_means k[])
 {
	 char **s;int i=1,j=0;
	  s=new char*[partitions+1];
	  for(;i<=partitions;i++)
		  {
			s[i]=(char *)malloc(7*sizeof(char));
			sprintf(s[i],"%d.txt",i);
		  }
    for(i=1;i<=partitions;i++)	  
	{
		FILE *f=fopen(s[i],"w");
		for(j=no_of_Tuples*i;j<no_of_Tuples*i+counter[i];i++)
			{
				int c=0;
				while(c<m)fprintf(f,"%d ",k[j].tuple[c++]);
				fprintf(f,"\n");
			}
			fclose(f);
	}
		  
 }
 int K_means:: Tuple_close2_partition( K_means &k, K_means m[])
 {
	 int i=1,d=Distance(k.tuple,m[i].tuple),p=1,d2;
	 for(;i<=partitions;i++)
		 if(d>(d2=Distance(k.tuple,m[i].tuple)))
			{ p=i;d=d2;}
	 return p;		
 }
 //Tuples,partition no, no of elements in that partition
 K_means K_means:: find_mean(K_means k[],int i , int c)
 {   
	 K_means o=new K_means(m,no_of_Tuples,partitions,1);
	 for(int j=no_of_Tuples*i;j<no_of_Tuples*i+c;j++)
		 for(int z=0;z<m;z++)o.tuple[z]+=k[j].tuple[z];
	 for(int z=0;z<m;z++)o.tuple[z]=(int)(o.tuple[z]/c);	
	 return o;
}
int main(int argc,char *argv[])
  {
     if(argc!=2)
        {  cout<<"EXITING... WRONG FORMAT OF INPUT!"<<endl<<endl;
         }
     else {
           if(fopen(argv[1],"r")==NULL)
              cout<<"NO SUCH FILE EXISTS!!..EXITING..."<<endl;
           else{ 
                 cout<<"The Following File is to be Clustered.."<<endl;
                 char s[50];
                 sprintf(s,"cat %s",argv[1]);
                 system(s);
                 FILE *f=fopen(argv[1],"r");
                 int  m=ReadFirstLine(f);fclose(f);
                 int no_of_Tuples=0,partitions=0;
                 f=fopen(argv[1],"r");
                 ReadFile(f,no_of_Tuples,partitions);fclose(f);
		 K_means obj=new K_means(m,no_of_Tuples,partitions,0);
                 K_means *Tuple=(K_means *)malloc(no_of_Tuples*(1+partitions)*sizeof(K_means));
                 for(int i=0;i<no_of_Tuples*(1+partitions);i++)
                     Tuple[i]=new K_means(m,no_of_Tuples,partitions,1);
                 f=fopen(argv[1],"r");
                 for(int i=0;i<no_of_Tuples;i++) 
                     obj.Read_Tuples(f,Tuple[i]);
                 fclose(f);
                 K_means **mean_partitions;
                 mean_partitions=(K_means **)malloc(2*sizeof(K_means *));//[2];
                 for(int i=0;i<2;i++) mean_partitions[i]=(K_means *)malloc([partitions+1]*sizeof(K_means));
                 for(int i =1;i<=partitions;i++)
                    { mean_partitions[0][i]=new K_means(m,no_of_Tuples,partitions,1);
                      mean_partitions[1][i]=new K_means(m,no_of_Tuples,partitions,1);
                     }   
				 for(int i=1;i<=partitions;i++)	 
                  mean_partitions[0][i]=Tuple[i-1];
				  
				 //k-means algo implementation 
				 while(!obj.equals(mean_partitions[0],mean_partitions[1]))
				 {
					 obj.initialize(obj.counter,partitions+1);//setting counters to zero
					 int i,j;
                     for(i=0;i<no_of_Tuples;i++)
					 {
						 j=obj.Tuple_close2_partition(Tuple[i],mean_partitions[0]);
						 Tuple[no_of_Tuples*j+((obj.counter[j])++)]=Tuple[i];
					 }//partitioning
					 //calculating  new mean
					 for(i=1;i<=partitions;i++)
					     mean_partitions[1][i]=obj.find_mean(Tuple,i,obj.counter[i]);
						 
				   };
				   obj.WriteFiles(&Tuple);
                  }
               }
  }
