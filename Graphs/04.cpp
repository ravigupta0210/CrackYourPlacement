// Flood Fill



class Solution {
public:
int row[4] = {0,-1,0,1};
int col[4] = {-1,0,1,0};
void dfs(vector<vector<int>>& image,vector<vector<int>>& ans,int sr,int sc,int color,int incolor){
    ans[sr][sc] = color;
    int n=image.size();
    int m =image[0].size();
    for(int i=0;i<4;i++){
        int nrow = sr+row[i];
        int ncol = sc+col[i];
        if(nrow >=0 && ncol >= 0 && nrow < n && ncol < m && image[nrow][ncol] == incolor && ans[nrow][ncol]!=color)
        dfs(image,ans,nrow,ncol,color,incolor);
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans =image;
        int incolor = image[sr][sc];
        dfs(image,ans,sr,sc,color,incolor);
        return ans;
    }
};
