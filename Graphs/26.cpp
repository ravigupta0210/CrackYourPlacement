// Negative weight cycle


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    if(n==0 || n==1) return 0;
	    vector<int> distance(n+1,1e9);
	    distance[edges[0][0]] = 0;
	     for(int i=1;i<=n;i++){
	         for(int j=0;j<edges.size();j++){
	             int u=edges[j][0];
	             int v=edges[j][1];
	             int w=edges[j][2];
	             if(distance[u]!=1e9 && (distance[u]+w)  < distance[v])
	             distance[v]=distance[u]+w;
	         }
	     }
	     bool flag = false;
	     for(int j=0;j<edges.size();j++){
	             int u=edges[j][0];
	             int v=edges[j][1];
	             int w=edges[j][2];
	             if(distance[u]!=1e9 && (distance[u]+w)  < distance[v])
	             flag = true;
	         }
	     if(flag == true) return 1;
	     else return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
