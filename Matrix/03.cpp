// Replace O's with X's


class Solution{
public:
void dfs(vector<vector<char>> &mat, int i, int j, int n, int m) {
        // base condition
        if(i < 0 or j < 0 or i >= n or j >= m or mat[i][j] != 'O') return;
        
        mat[i][j] = '~'; // will be replaced back to 'O'
        dfs(mat, i-1, j, n, m);
        dfs(mat, i+1, j, n, m);
        dfs(mat, i, j-1, n, m);
        dfs(mat, i, j+1, n, m);
}
vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
        // dfs on 1st and nth row
        for(int i = 0; i < m; i++) {
            if(mat[0][i] == 'O') dfs(mat, 0, i, n, m);
            if(mat[n - 1][i] == 'O') dfs(mat, n - 1, i, n, m);
        }
        
        // dfs on 1st and mth col
        for(int i = 0; i < n; i++) {
            if(mat[i][0] == 'O') dfs(mat, i, 0, n, m);
            if(mat[i][m - 1] == 'O') dfs(mat, i, m - 1, n, m);
        }
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                mat[i][j] = mat[i][j] == 'O' ? 'X' : mat[i][j];
                mat[i][j] = mat[i][j] == '~' ? 'O' : mat[i][j];
            }
        
        return mat;
}
};
