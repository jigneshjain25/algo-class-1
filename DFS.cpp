#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
#define rep(i,a,b) for(i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
int TIME=0;
using namespace std;
class node{
    public:
    int name;
    vector<int> adj;
    bool explored;
    int d;
    int s;
    int f;
    int pd;
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
            y.s=-1;
            y.f=-1;
            y.pd=-1;
            nodes.pb(y);

            }
    }
};
void DFS(graph &g,int s){
    ++TIME;
    g.nodes[s-1].s=TIME;
    g.nodes[s-1].explored=true;
    for(int i=0;i<g.nodes[s-1].adj.size();i++)
    {
        if(!g.nodes[g.nodes[s-1].adj[i]-1].explored)
            {
            g.nodes[g.nodes[s-1].adj[i]-1].pd=s;
            //g.nodes[g.nodes[s-1].adj[i]-1].d=g.nodes[s-1].d+1;
            DFS(g,g.nodes[s-1].adj[i]);

            }
    }
    ++TIME;
    g.nodes[s-1].f=TIME;
}
int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int i=0,j,temp;
    graph g(8);
   while(1){
        fin>>temp;
        if(fin.eof())
            break;
        if(temp==99){
            i++;
            continue;
        }
        g.nodes[i].adj.pb(temp);

    }
    DFS(g,2);
    REP(j,0,g.size)
        cout<<g.nodes[j].explored<<" ";
}
