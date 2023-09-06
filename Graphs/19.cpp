// Prerequisite Tasks


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& p) {
	    // Code here
	    unordered_map<int,list<int>> adj;
	    vector<int> indegree(N);
	    for(int i=0;i<p.size();i++){
	        int u=p[i].first,v=p[i].second;
	        adj[u].push_back(v);
	        indegree[v]++;
	    }
	    queue<int> q;
	    int count=0;
	    for(int i=0;i<N;i++) if(indegree[i] == 0) q.push(i);
	    while(!q.empty()){
	        int front=q.front();
	        q.pop();
	        count++;
	        for(auto i:adj[front]){
	            indegree[i]--;
	            if(indegree[i]==0){
	                q.push(i);
	            }
	        }
	    }
	    return count==N;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
