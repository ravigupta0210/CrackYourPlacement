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


//  Detect Cycle In A Directed Graph



#include <bits/stdc++.h> 

int detectCycleInDirectedGraph(int v, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first-1;
        int v=edges[i].second-1;
        adj[u].push_back(v);
    }
    queue<int> q;
    vector<int> indegree(v);

    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    for(int i=0;i<v;i++){
        if(indegree[i]==0)
        q.push(i);
    }
    int count=0;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        count++;
        for(auto i:adj[front]){
            indegree[i]--;
            if(indegree[i]==0)
            q.push(i);
        }
    }
    return !(count==v);
}



//  Topological Sort



#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    queue<int> q;
    vector<int> indegree(v);

    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    for(int i=0;i<v;i++){
        if(indegree[i]==0)
        q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);

        for(auto i:adj[front]){
            indegree[i]--;
            if(indegree[i]==0)
            q.push(i);
        }
    }
    return ans;
}



// Topological sort



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
    queue<int> q;
    vector<int> indegree(v);

    for(int i=0;i<v;i++){
        for(auto j:adj[i])
        indegree[j]++;
    }

    for(int i=0;i<v;i++){
        if(indegree[i]==0)
        q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);

        for(auto i:adj[front]){
            indegree[i]--;
            if(indegree[i]==0)
            q.push(i);
        }
    }
    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
