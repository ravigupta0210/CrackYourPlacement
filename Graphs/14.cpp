// Time Needed to Inform All Employees


class Solution {
public:
void solve(int s,int &ans,int sum,vector<int> &v,vector<vector<int>> &g){
    sum += v[s];
    ans = max(ans,sum);
    for(auto &i: g[s]){
        solve(i,ans,sum,v,g);
    }
}
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1) adj[manager[i]].push_back(i);
        }
        int ans=0;
        solve(headID,ans,0,informTime,adj);
        return ans;
    }
};
