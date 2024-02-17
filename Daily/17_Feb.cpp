//  Prim's MST



#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<g.size();i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> key(n+1,INT_MAX);
    vector<bool> mst(n+1,false);
    vector<int> parent(n+1,-1);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    key[1]=0;

    while(!pq.empty()){
        int w=pq.top().first;
        int node=pq.top().second;
        mst[node]=true;
        pq.pop();

        for(auto i:adj[node]){
            int v=i.first;
            int w=i.second;

            if(mst[v]==false && w<key[v]){
                key[v]=w;
                parent[v]=node;
                pq.push({w,v});
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
}
