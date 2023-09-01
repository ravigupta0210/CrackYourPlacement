//Find Eventual Safe States


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> dis(n,0);
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(auto x:graph[i]){
                adj[x].push_back(i);
                dis[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(dis[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto i:adj[front]){
                dis[i]--;
                if(dis[i] == 0) q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
