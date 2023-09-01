//Number of Operations to Make Network Connected

class Solution {
public:
void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i])
        dfs(i,visited,adj);
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        unordered_map<int,list<int>> adj;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0],v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0;
        unordered_map<int,bool> visited;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,adj);
            }
        }
        return count-1;
    }
};
