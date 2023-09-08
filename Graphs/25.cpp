// Cheapest Flights Within K Stops


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto v:flights){
            adj[v[0]].push_back({v[1],v[2]});
        }

        queue<pair<int,int>> q;
        q.push({src,0});
        vector<int> dist(n,1e9);
        int stop=0;
        while(!q.empty() && stop<=k){
            int size=q.size();
            while(size--){
                auto [u,d] = q.front();
                q.pop();
                for(auto [v,w] : adj[u]){
                    if(dist[v] > d+w){
                        dist[v] = d+w;
                        q.push({v,dist[v]});
                    }
                }
            }
            stop++;
        }
        if(dist[dst]!=1e9) return dist[dst];
        else return -1;
    }
};
