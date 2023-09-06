// Find the City With the Smallest Number of Neighbors at a Threshold Distance


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(auto node:edges){
            dist[node[0]][node[1]]= node[2];
            dist[node[1]][node[0]] = node[2];
        } 

        for(int i=0;i<n;i++) dist[i][i] = 0;

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][j]> dist[i][k]+dist[k][j] && dist[i][k]!=1e9 && dist[k][j] != 1e9)
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
        vector<int> cities(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=distanceThreshold)
                cities[i]++;
            }
        }
        int mini = 1e9;
        for(int i=0;i<n;i++)
        mini=min(mini,cities[i]);

        int maxi=-1;
        for(int i=0;i<n;i++)
        if(cities[i]==mini) maxi=max(maxi,i);
        return maxi;
    }
};
