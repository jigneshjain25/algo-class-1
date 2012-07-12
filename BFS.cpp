#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
#define rep(i,a,b) for(i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
using namespace std;
class node{
    public:
    int name;
    vector<int> adj;
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
    int s=2;
    g.nodes[s-1].explored=true;
    g.nodes[s-1].d=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        rep(i,0,g.nodes[v-1].adj.size()){
            if(!g.nodes[g.nodes[v-1].adj[i]-1].explored){
                g.nodes[g.nodes[v-1].adj[i]-1].explored=true;
                q.push(g.nodes[v-1].adj[i]);
                g.nodes[g.nodes[v-1].adj[i]-1].d=g.nodes[v-1].d+1;
            }
        }
    }
    REP(j,0,g.size){
        cout<<g.nodes[j].d<<" ";
    }


}




