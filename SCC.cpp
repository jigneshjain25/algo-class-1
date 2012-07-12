#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
#define rep(i,a,b) for(i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
using namespace std;
#include<map>
#include<algorithm>
int TIME=0,S=-1;
using namespace std;
class node{
    public:
    int name;
    vector<int> adj;
    bool explored;
    int leader;
};
map<int,node> ph;

class graph{
    public:
    int size;
    vector<node> nodes;
    graph(){
    }
    graph(int n){
        size=n;
        REP(i,0,size)
            {

            node y;
            y.name=i+1;
            y.explored=false;
            y.leader=-1;
            nodes.pb(y);

            }
        for(int j=1;j<=size;j++)
            {
                ph[j]=nodes[j-1];
            }
    }
};
void dfs2(graph &g,int s){


    g.nodes[s-1].explored=true;
    g.nodes[s-1].leader=S;
    for(int i=0;i<g.nodes[s-1].adj.size();i++)
            if(!g.nodes[g.nodes[s-1].adj[i]-1].explored)
                    dfs2(g,g.nodes[s-1].adj[i]);
}
void dfs1(graph &g,int s){

    g.nodes[s-1].explored=true;

    for(int i=0;i<g.nodes[s-1].adj.size();i++)
            if(!g.nodes[g.nodes[s-1].adj[i]-1].explored)
                    dfs1(g,g.nodes[s-1].adj[i]);

    ++TIME;
    ph[TIME]=g.nodes[s-1];
}
void dfsloop1(graph &g)
{
    TIME=0;
    for(int i=g.size;i>=1;i--)
    {
        if(!g.nodes[i-1].explored)
            dfs1(g,i);
    }
}
void dfsloop2(graph &g)
{
    S=-1;
    for(int i=g.size;i>=1;i--)
    {
        node x=ph[i];
        int m=x.name;
        if(!g.nodes[m-1].explored)
            {
                S=m;
                dfs2(g,m);
            }
    }

}
bool myf(int a,int b)
{
    return(b<a);
}
int main(){
    int i=0,j,temp,a,b;
    ifstream fin("SCC.txt");
    ofstream fout("output.txt");
    graph g(875714);
   while(1){
        fin>>a>>b;
        if(fin.eof())
            break;
        g.nodes[a-1].adj.pb(b);

    }
    fin.close();
    ifstream ffin("SCC.txt");
    graph gt(875714);
    while(1){
        ffin>>a>>b;
        if(ffin.eof())
            break;
        gt.nodes[b-1].adj.pb(a);

    }

   // DFS(g,2);
    /*rep(j,0,gt.size){

        rep(i,0,gt.nodes[j].adj.size())
            cout<<gt.nodes[j].adj[i]<<" ";
        cout<<endl;
        }*/

    dfsloop1(gt);
    dfsloop2(g);

        map<int,int> ans;
        int m;
        for(m=1;m<g.size;m++)
            ans[m]=0;
        for(m=0;m<g.size;m++)
            ans[g.nodes[m].leader]++;
        vector<int> final;
        for(m=0;m<g.size;m++)
            final.pb(ans[m+1]);
        sort(final.begin(),final.end(),myf);
      //  for(m=0;m<final.size();m++)
        //cout<<final[m]<<" ";
        fout<<final[0]<<" "<<final[1]<<" "<<final[2]<<" "<<final[3]<<" "<<final[4];


}
