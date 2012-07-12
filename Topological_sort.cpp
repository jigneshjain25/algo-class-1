#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
#include<algorithm>
#include<vector>
#define rep(i,a,b) for(i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
using namespace std;
int n=6;
class node{
    public:
    int name;
    vector<int> adj;
    bool explored;
    int d;
    int label;
};
bool myfunction (node i,node j) { return (i.label<j.label); }

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
            y.label=-1;
            y.explored=false;
            y.d=-1;
            nodes.pb(y);

            }
    }
};
void DFS(graph &g,int s){
    g.nodes[s-1].explored=true;
    for(int i=0;i<g.nodes[s-1].adj.size();i++){
        if(!g.nodes[g.nodes[s-1].adj[i]-1].explored){
            g.nodes[g.nodes[s-1].adj[i]-1].d=g.nodes[s-1].d+1;
            DFS(g,g.nodes[s-1].adj[i]);
            }
    }
    g.nodes[s-1].label=n;
    n--;
}
int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int i=0,j,temp;
    graph g(n);
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

    for(int m=0;m<g.size;m++){
        if(!g.nodes[m].explored){
            DFS(g,m+1);
        }
    }


    REP(j,0,g.size)
        cout<<g.nodes[j].label<<" ";
}
