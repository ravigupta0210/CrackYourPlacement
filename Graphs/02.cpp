// DFS of Graph



class Solution {
  public:
  void dfs(unordered_map<int,bool> &visited,vector<int> &ans,vector<int> adj[],int node){
      ans.push_back(node);
      visited[node] = 1;
      for(auto i:adj[node]){
          if(!visited[i])
          dfs(visited,ans,adj,i);
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        unordered_map<int,bool> visited;
        dfs(visited,ans,adj,0);
        return ans;
    }
};
