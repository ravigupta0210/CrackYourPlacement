// Number of Islands


class Solution {
public:
int row[4] = {0,-1,0,1};
int col[4] = {-1,0,1,0};
void solve(vector<vector<char>>& grid,int i,int j){
if(i<0 || j<0 || i >= grid.size() || j>= grid[0].size() || grid[i][j]!='1') return ;
grid[i][j] = '0';
for(int k=0;k<4;k++){
    solve(grid,i+row[k],j+col[k]);
}
}
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n= grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    solve(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
