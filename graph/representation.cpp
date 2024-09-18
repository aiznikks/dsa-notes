#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// sc -> N*N

int main(){
    int n,m;
    cin >>n >> m;

    // graph here
    int adj[n+1][m+1]
    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}
// adj list 
// create an array [n+1],
// this array contains list and list is nothing but vector
int main(){
    int n,m;
    cin >>n >> m;

    // graph here
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}