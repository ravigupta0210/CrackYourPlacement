// Most Stones Removed with Same Row or Column


class Solution {
public:
void dfs(vector<int> adj[],int node,vector<int>& removed){
    removed[node] = 1;
    for(auto i:adj[node]){
        if(!removed[i]) dfs(adj,i,removed);
    }
}
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && (stones[i][0] == stones[j][0] || stones[i][1]==stones[j][1])) adj[i].push_back(j);
            }
        }
        vector<int> removed(n,0);
        int ans=n;
        for(int i=0;i<n;i++){
            if(!removed[i]){
                dfs(adj,i,removed);
                ans--;
            }
        }
        return ans;
    }
};
