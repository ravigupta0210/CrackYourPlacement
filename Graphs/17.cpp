// As Far from Land as Possible


class Solution {
public:
bool isValid(int row,int col,int n,vector<vector<int>>& grid){
    if(row>=0 && row<n && col>=0 && col<n && grid[row][col]==0) return true;
    else return false;
}
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(grid[i][j]==1) q.push({i,j});

        int ans=0;
        if(q.size() == n*n) return -1;
        while(!q.empty()){
            int size=q.size();
            ans++;
            while(size--){
                int row = q.front().first, col=q.front().second;
                q.pop();
                int dx[] = {0,0,-1,1};
                int dy[] = {-1,1,0,0};
                for(int i=0;i<4;i++){
                    int newrow = row+dx[i], newcol = col+dy[i];
                    if(isValid(newrow,newcol,n,grid)){
                        q.push({newrow,newcol});
                        grid[newrow][newcol] = 1;
                    }
                }
            }
        }
        return ans-1;
    }
};
