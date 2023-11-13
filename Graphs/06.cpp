// Detect cycle in an undirected graph



class Solution {
  public:
  bool dfs(unordered_map<int,bool> &visited,int node,int parent,vector<int> adj[]){
      visited[node] = 1;
      for(auto i: adj[node]){
          if(!visited[i]){
              bool ans =  dfs(visited,i,node,adj);
              if(ans) return true;
          }
          else if(i!=parent){
              return true;
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool> visited;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans = dfs(visited,i,-1,adj);
                if(ans) return true;
            }
        }
        return false;
    }
};
