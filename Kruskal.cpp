//on entering the adjacency matrix of the Graph
//it provides the minimum spanning tree
// check 106 line!
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
using namespace std;
struct node
{
vector<int> adjacent_node_wts;
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
void inputAdj_matrix(vector<node> &G,int N)
{
for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
       {  
          int num=0;
          cin>>num;
          G[i].adjacent_node_wts[j]=num;
        }
}
vector<G> convert_2_setofedges(vector<node> &a,int N , int &ct)
 {
   
   vector<G> edge(N*N);
   for(int i=0;i<N;i++)
     for(int j=0;j<N;j++)
        if(i!=j && a[i].adjacent_node_wts[j]!=0)
        {
          edge[ct].v1=i+1;
          edge[ct].v2=j+1;
          edge[ct].wt=a[i].adjacent_node_wts[j];
          ct++; 
        }
    return edge;    
 }
 
void generate_forest_representatives(vector<int> &vertex_presence,int N)
 {
  //forming representatives of trees
     
     //the maximal element is the representative!
     //auxiliary data structures
     
     vector<bool> vp(N+1);
     fill_n(vp.begin(),N+1,0);//initialized
      
     for(int i=1;i<=N;i++)
       {
       if(!vp[i])
       {
        stack <int> s;
        int j=i;
         do{vp[j]=1;s.push(j);
         }while((j=vertex_presence[j])!=0&&(j!=vertex_presence[j]));  
          int rep=s.top();
          
          vertex_presence[rep]=vertex_presence[rep]==0?rep:vertex_presence[rep];
          
          s.pop();
          labl:if(!s.empty())
             { 
               vertex_presence[s.top()]=rep;s.pop();
               goto labl;
             }   
        }
        }
    
 }
Pair create_pair(int a,int b)
 {
  (a<b)?:a^=b^=a^=b;
  Pair p;
  p.a=a;p.b=b;
  return p;
 }
bool chk_presence_of_pair(vector<Pair> &p_set,Pair &p) 
{
		bool chk=true;
           for(int j=0;j<p_set.size();j++)
               if(p.a==p_set[j].a&&p.b==p_set[j].b)
                   {chk=false;break;}
        return chk;           
}
int Kruskals_mst(vector<node> &Gr)
{ 
  int count=0,flg=0,lstedge=0,total=0,forests=0; int N=Gr.size();
  //mst will contain only the edges of the mst, edges-contain all wt having edges
  vector<G> mst,edge;
  edge=convert_2_setofedges(Gr,N,count);//this is just to show the type of parameter passings possible
 //sorting of the edges
  sort(edge.begin(),edge.begin()+count,comp);
 //auxiliary data structures
 vector<int> vertx_presence(N+1);//vertices, keeps track of the vertices 
 vector<bool> vp(N+1);//to indicate the particular vertex is used
  vector<Pair> set_pair;//to store connected forests
 fill_n(vertx_presence.begin(),N+1,0);
 fill_n(vp.begin(),N+1,0);
  
  //creation of forests 
  forests=flg=N;
   for(int i=0;i<count;i++)
     if(!(vp[edge[i].v1]&vp[edge[i].v2]) && flg>0)       
         {   
             flg-=(vp[edge[i].v1]^vp[edge[i].v2]?2:1);//keeps track of increasing visited vertices
         	//visited vertices 
             vp[edge[i].v1]=vp[edge[i].v2]=1;
             
            //a type of topological sorting 
            if(edge[i].v1<edge[i].v2)
                 vertx_presence[edge[i].v1]=edge[i].v2;
            else vertx_presence[edge[i].v2]=edge[i].v1;
            
            mst.push_back(edge[i]);
            forests--;//that many unconnected component remains
            lstedge=i;//keeps track of the last edge added
            total+=edge[i].wt;
         }
   forests--;
    //set representative form of the forests
    generate_forest_representatives(vertx_presence,N);        
     //after transforming to representative elements
     for(int i=lstedge+1;i<count;i++)
     {
        int vrtx1=edge[i].v1,vrtx2=edge[i].v2;
        
        int rep_vrtx1=vertx_presence[vrtx1],rep_vrtx2=vertx_presence[vrtx2];
        if(rep_vrtx1!=rep_vrtx2)
         {
           Pair p=create_pair(rep_vrtx1,rep_vrtx2);
           //to check if a pair has already been used
           
           if(chk_presence_of_pair(set_pair,p))
           {        
             set_pair.push_back(p);
             mst.push_back(edge[i]);
             total+=edge[i].wt;
             forests--;
           }
          if(!forests)break; 
         }      
     }  
  //displaying the mst           
 for(int i=0;i<mst.size();i++)
     cout<<'\n'<<mst[i].v1<<'\t'<<mst[i].v2<<'\t'<<mst[i].wt;
     cout<<'\n'<<"The total weight is "<<total<<'\n';
  
   return 1;
 
} 
int main()
{
 int N=0,flg=0;
 L1:cout<<(flg?"Please Re-":"")<<"Enter how many vertices there are in the 'dag'!\n";
 cin>>N;
 N>0?:flg=1;//checking if the entered value is positive
 if(N<1)goto L1;
 vector<node> adj_Mat(N);
 //memory reserving
 for(vector<node>:: iterator i=adj_Mat.begin();i!=adj_Mat.end();i++)
   {
     i->adjacent_node_wts.reserve(N); 
     fill_n(i->adjacent_node_wts.begin(),N,0);
    } 
    //taking inputs;
 inputAdj_matrix(adj_Mat,N);  
  //generating mst
  flg=Kruskals_mst(adj_Mat);
  cout<<(flg?"MST Printed!!\n":"FAILED TO GENERATE THE MST.\n");
return 0;
}