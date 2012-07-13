#include<iostream>
#include<vector>
using namespace std;
#define pb push_back
#include<fstream>
#include<string.h>
#define rep(i,a,b) for(i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#include<algorithm>
void remove(vector<int> &v,int m)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==m){
            v.erase(v.begin()+i);
            break;}
    }
}
class edge
{public:
  int a;
  int b;
  int weight;
};
class node{
    public:
    int name;
    vector<pair<int,int> > adj;
    bool explored;
    int d;
};
class graph{
    public:
    int size;
    vector<node> nodes;

    graph(){
    }
    graph(int n){
        size=n;
        REP(i,0,size){

            node y;
            y.name=i+1;
            y.explored=false;
            y.d=-1;
            nodes.pb(y);

            }
    }
};



int main()
{
    ifstream fin("final.txt");
    ofstream fout("test.txt");
    int temp,i=0;
    graph g(200);
    vector<edge> edges;
    vector<int> x,v;
    x.pb(1);
    REP(j,2,201)
        v.pb(j);
    int sp[200];
    memset(sp,1000000,sizeof(sp));
    sp[0]=0;

    pair<int,int> p;
    while(1)
    {
        fin>>p.first>>p.second;

        if(fin.eof())break;
        if(p.first==-1){i++;continue;}
        g.nodes[i].adj.pb(p);
    }
    /*REP(m,0,200)
    {
        REP(n,0,g.nodes[m].adj.size())
            fout<<g.nodes[m].adj[n].first<<" "<<g.nodes[m].adj[n].second<<" ";
        fout<<endl;
    }*/
    edge t;
    while(x.size()!=200)
    {
       edges.clear();
       for(int m=0;m<x.size();m++)
       {
         //  scan x[m] s adj list
         for(int l=0;l<g.nodes[x[m]-1].adj.size();l++)
         {
             if(find(x.begin(),x.end(),g.nodes[x[m]-1].adj[l].first)==x.end())
                   {
                        t.a=x[m];
                        t.b=g.nodes[x[m]-1].adj[l].first;
                        t.weight=g.nodes[x[m]-1].adj[l].second;
                        edges.pb(t);
                   }

         }
       }
       int min=1000000,vst,wst,lst;
       for(int n=0;n<edges.size();n++)
       {
           //minimise sp[edges[n].a-1]+edges[n].weight
           if((sp[edges[n].a-1]+edges[n].weight)<min)
           {
               min=sp[edges[n].a-1]+edges[n].weight;
               vst=edges[n].a;
               wst=edges[n].b;
               lst=edges[n].weight;

           }

       }
       x.pb(wst);
        remove(v,wst);
        sp[wst-1]=sp[vst-1]+lst;


    }
    /*for(int x=0;x<200;x++)
        cout<<sp[x]<<" ";*/
        fout<<sp[6]<<","<<sp[36]<<","<<sp[58]<<","<<sp[81]<<","<<sp[98]<<","<<sp[114]<<","<<sp[132]<<","<<sp[164]<<","<<sp[187]<<","<<sp[196];

}
