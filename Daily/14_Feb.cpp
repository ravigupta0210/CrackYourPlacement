//  Cycle Detection In Undirected Graph



#include<bits/stdc++.h>
bool bfs(int node,unordered_map<int,bool> &visited,unordered_map<int,int> &parent
,unordered_map<int,list<int>> &adj){
    visited[node]=true;
    parent[node]=-1;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
    int front=q.front();
    q.pop();
    for(auto i:adj[front]){
        if(visited[i] && i!=parent[front])
        return true;
        else if(!visited[i]){
            q.push(i);
            parent[i]=front;
            visited[i]=true;
        }
    }
    }
    return false;
}
bool dfs(int node,unordered_map<int,bool> &visited,int parent,unordered_map<int,list<int>> &adj){
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            bool aageka=dfs(i,visited,node,adj);
            if(aageka) return true;
        }
        else if(i!=parent) return true;
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            // bool ans=bfs(i,visited,parent,adj);
            bool ans = dfs(i,visited,-1,adj);
            if(ans) return "Yes";
        }
    }
    return "No";
}
