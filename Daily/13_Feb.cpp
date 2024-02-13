// Clone Graph


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
Node* dfs(unordered_map<Node*,Node*> &mp,Node* node){
    vector<Node*> neigh;
    Node* clone=new Node(node->val);
    mp[node]=clone;
    for(auto it:node->neighbors){
        if(mp.find(it)!=mp.end()){
            neigh.push_back(mp[it]);
        }
        else neigh.push_back(dfs(mp,it));
    }
    clone->neighbors = neigh;
    return clone;
}
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL) return NULL;
        if(node->neighbors.size()==0){
            Node* clone = new Node(node->val);
            return clone;
        }
        return dfs(mp,node);
    }
};



// DFS of Graph



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(unordered_map<int,bool> &visited,vector<int> &ans,vector<int> adj[],int node){
        visited[node]=1;
        ans.push_back(node);
        for(auto it:adj[node]){
            if(!visited[it])
            dfs(visited,ans,adj,it);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        unordered_map<int,bool> visited;
        vector<int> ans;
        dfs(visited,ans,adj,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
