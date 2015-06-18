//actually kruskal's done here!!

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
using namespace std;
struct city_i
{
vector<int> cst;
};
struct G
{
  int v1,v2,wt;
};
bool comp(G s, G t)
{
 return (s.wt<=t.wt);
}
struct Pair
{
int a,b;
};
int main()
{
 int N=0;
 cin>>N;
 vector<city_i> a(N);
 //fill(a.begin(),N,cst(N));
 for(vector<city_i>:: iterator i=a.begin();i!=a.end();i++)
   {
     i->cst.reserve(N); 
     fill_n(i->cst.begin(),N,0);
    } 
 for(int i=0;i<2*N;i++)
    for(int j=0;j<N;j++)
       {  
          int num=0;
          cin>>num;
          a[i%N].cst[j]+=num;
        }
  cout<<'\n';      
 for(int i=0;i<N;i++)
    {for(int j=0;j<N;j++)
        cout<<a[i].cst[j]<<' ';
     cout<<'\n';
     }       
 int ct=0;
 vector<G> edge(N*N);
 for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
        if(i!=j)
        {
          edge[ct].v1=i+1;//adjusted for values
          edge[ct].v2=j+1;
          edge[ct].wt=a[i].cst[j];
          ct++; 
        }
 sort(edge.begin(),edge.begin()+ct,comp);
 vector<int> vertx_presence(N+1);//vertices - 1 to N
 vector<bool> vp(N+1);
 fill_n(vertx_presence.begin(),N+1,0);
 fill_n(vp.begin(),N+1,0);
 
 //int total=edge[0].wt;
 vector<G> mst;
 mst.push_back(edge[0]);
  
  if(edge[0].v1<edge[0].v2)
      vertx_presence[edge[0].v1]=edge[0].v2;
  else vertx_presence[edge[0].v2]=edge[0].v1;
  vp[edge[0].v1]=vp[edge[0].v2]=1;
   int lstedge=0; 
    for(int i=1;i<ct;i++)
     if(!(vp[edge[i].v1]&vp[edge[i].v2]))       
         {  vp[edge[i].v1]=vp[edge[i].v2]=1;
  
            if(edge[i].v1<edge[i].v2)
            vertx_presence[edge[i].v1]=edge[i].v2;
            else vertx_presence[edge[i].v2]=edge[i].v1;
            mst.push_back(edge[i]);
            lstedge=i;
            //total+=edge[i].wt;
         }
    for(int i=0;i<mst.size();i++)
     cout<<'\n'<<mst[i].v1<<'\t'<<mst[i].v2<<'\t'<<mst[i].wt;
      cout<<'\n';
   //total forests
   int forests=0;
   for(int i=1;i<=N;i++){cout<<i<<"->"<<vertx_presence[i]<<' ';if(!vertx_presence[i])forests++;}
     cout<<forests<<'\n';
     //starting from the lstedge till forest turns tree
     forests--;//joining of that many forests guarantees a mst 
     //forming representatives of trees
     //clearing vp
     fill_n(vp.begin(),N+1,0);

     for(int i=1;i<=N;i++)
       {
       if(!vp[i])
       {
        stack <int> s;
        int j=i;
         do{vp[j]=1;s.push(j);
         }while((j=vertx_presence[j])!=0&&(j!=vertx_presence[j]));  
          int rep=s.top();
          vertx_presence[rep]=vertx_presence[rep]==0?rep:vertx_presence[rep];
          s.pop();
          labl:if(!s.empty())
             {  //int indx=s.pop();
               vertx_presence[s.top()]=rep;s.pop();
               goto labl;
             }
             //cout<<'\n';
        }
       }
       //after transforming to a representative set
   for(int i=1;i<=N;i++)cout<<i<<"->"<<vertx_presence[i]<<' ';cout<<'\n';
        vector<Pair> set_pair;
   for(int i=lstedge+1;i<ct;i++)
     {
        int vrtx1=edge[i].v1,vrtx2=edge[i].v2;
        cout<<vrtx1<<','<<vrtx2<<'\n';
        int rep_vrtx1=vertx_presence[vrtx1],rep_vrtx2=vertx_presence[vrtx2];
        //code
        
        if(rep_vrtx1!=rep_vrtx2)
         {
           cout<<"representatives-"<<rep_vrtx1<<','<<rep_vrtx2<<'\n';
           Pair p;
           (rep_vrtx1<=rep_vrtx2)?:rep_vrtx1^=rep_vrtx2^=rep_vrtx1^=rep_vrtx2;
           p.a=rep_vrtx1;p.b=rep_vrtx2;
           //to check if a pair has already been used
           bool chk=true;
           for(int j=0;j<set_pair.size();j++)
               if(p.a==set_pair[j].a&&p.b==set_pair[j].b)
                   {chk=false;break;}
           
           if(chk){        
           set_pair.push_back(p);
           mst.push_back(edge[i]);forests--;}
           if(!forests)break; 
         }      
     }  
             
 for(int i=0;i<mst.size();i++)
     cout<<'\n'<<mst[i].v1<<'\t'<<mst[i].v2<<'\t'<<mst[i].wt;
     cout<<'\n';
 //cout<<'\n'<<total<<'\n';                   
return 0;
}
