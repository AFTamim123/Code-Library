#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+2;
vector<int> tr[N],vis(N),par(N);
int dis=-1,farthest_node=-1;
void farthest(int node, int p, int depth) {
    par[node]=p;
    if(depth>dis || (depth==dis && node>farthest_node)) {
        dis=depth;
        farthest_node=node;
    } 
    for(auto &it: tr[node]) {
        if(vis[it] || it==p) continue;
        farthest(it,node,depth+1);
    }
}
void get_diameter_nodes() {

    dis=-1,farthest_node-1;
    farthest(1,-1,0);
    int u=farthest_node;

    dis=-1,farthest_node-1;
    farthest(u,-1,0);
    int v=farthest_node;
    
}

void get_diameter_nodes() {
    
    dis=-1,farthest_node-1;
    farthest(1,-1,0);
    int u=farthest_node;

    dis=-1,farthest_node-1;
    farthest(u,-1,0);
    int v=farthest_node;
    
}
void print_path(int v) {
    int node = v;
    while (node!=-1)
    {
        vis[node]=1;
        node=par[node];
    }
}
int32_t main() {
     
    return 0;
}