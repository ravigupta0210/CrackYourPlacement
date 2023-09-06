// Minimum Spanning Tree


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        vector<int> key(n),parent(n);
        vector<bool>  mst(n);
        for(int i=0;i<n;i++){
            mst[i]=false;
            parent[i]=-1;
            key[i]=INT_MAX;
        }
        
        key[0]=0,parent[0]=-1;
        for(int i=0;i<n;i++){
            int mini = INT_MAX;
            int u;
            for(int v=0;v<n;v++)
            {
                if(mini>key[v] && mst[v]==false){
                    u=v;
                    mini=key[v];
                }
            }
            mst[u]=true;
            for(auto it:adj[u]){
                int v=it[0];
                int w=it[1];
                if(w<key[v] && mst[v]==false){
                    key[v]=w;
                    parent[v]=u;
                }
            }
        }
        int sum=0;
        for(auto i:key) sum+=i;
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
