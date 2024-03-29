//  Find the number of islands



class Solution {
  public:
  
  int row[8] = {-1,-1,-1,0,1,1,1,0};
  int col[8] ={-1,0,1,1,1,0,-1,-1};
    
    void solve(vector<vector<char>>& grid, int i,int j){
        if(i < 0 || j<0 || i>= grid.size() || j>= grid[0].size() || grid[i][j] != '1')
        return ;
        grid[i][j] = '0';
        for(int k=0;k<8;k++){
            solve(grid,i+row[k],j+col[k]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(),m=grid[0].size(), ans=0;
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
