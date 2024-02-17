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



//  Minimum Spanning Tree



#include<bits/stdc++.h>
bool cmp(vector<int> &a,vector<int> &b){
  return a[2]<b[2];
}
int findParent(int node,vector<int> &parent){
  if(parent[node]==node)
  return node;
  return parent[node]=findParent(parent[node], parent);
}
void unionSet(int u,int v,vector<int> &parent,vector<int> &rank){
  u=findParent(u, parent);
  v=findParent(v, parent);

  if(rank[u]<rank[v])
  parent[u]=v;
  else if(rank[v]<rank[u])
  parent[v]=u;
  else {parent[v]=u;
  rank[u]++;}
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  sort(edges.begin(),edges.end(),cmp);
  vector<int> parent(n),rank(n);
  for(int i=0;i<n;i++){
    parent[i]=i;
    rank[i]=0;
  }
  int ans=0;
  for(int i=0;i<edges.size();i++){
    int u=findParent(edges[i][0],parent);
    int v=findParent(edges[i][1],parent);
    int w=edges[i][2];

    if(u!=v){
      ans+=w;
      unionSet(u,v,parent,rank);
    }
  }
  return ans;
}
