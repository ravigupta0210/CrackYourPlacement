// BFS of graph


class Solution {
  public:
  void bfs(unordered_map<int,bool> &visited,vector<int> &ans,vector<int> adj[],int node){
      queue<int> q;
      q.push(node);
      visited[node] = 1;
      while(!q.empty()){
          int frontNode = q.front();
          q.pop();
          ans.push_back(frontNode);
          for(auto i:adj[frontNode]){
              if(!visited[i]){
                  q.push(i);
                  visited[i] = 1;
              }
          }
      }
  }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool> visited;
        vector<int> ans;
        bfs(visited,ans,adj,0);
        return ans;
    }
};
