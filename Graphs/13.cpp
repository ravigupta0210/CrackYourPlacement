// Strongly Connected Components (Kosaraju's Algo)


class Solution
{
	public:
	void dfs(int node,vector<vector<int>>& adj,unordered_map<int,bool> &visited,stack<int> &st){
	    visited[node] =true;
	    for(auto it:adj[node]){
	        if(!visited[it])
	        dfs(it,adj,visited,st);
	    }
	    st.push(node);
	}
	void revdfs(int node,unordered_map<int,list<int>>& adj,unordered_map<int,bool> &visited){
	    visited[node] =true;
	    for(auto it:adj[node]){
	        if(!visited[it])
	        revdfs(it,adj,visited);
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int> st;
        unordered_map<int,bool> visited;
        for(int i=0;i<V;i++){
            if(!visited[i])
            dfs(i,adj,visited,st);
        }
        unordered_map<int,list<int>> transpose;
        for(int i=0;i<V;i++){
            visited[i] = false;
            for(auto u:adj[i])
            transpose[u].push_back(i);
        }
        int count =0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if(!visited[top])
            {
                count++;
                revdfs(top,transpose,visited);
            }
        }
        return count;
    }
};
