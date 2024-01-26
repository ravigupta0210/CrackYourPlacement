// Permutations


class Solution {
public:
void solve(vector<int>& nums,int index,vector<vector<int>> &ans){
    if(index>=nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int j=index;j<nums.size();j++){
        swap(nums[index],nums[j]);
        solve(nums,index+1,ans);
        swap(nums[index],nums[j]);
    }

}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        solve(nums,index,ans);
        return ans;
    }
};

// N-Queens


class Solution {
public:
bool isSafe(int row,int col,vector<string> &board,int n){
    int x=row,y=col;
    while(y>=0){
        if(board[x][y]=='Q') return false;
        y--;
    }
    x=row;
    y=col;
    while(y>=0 && x>=0){
        if(board[x][y]=='Q') return false;
        y--;
        x--;
    }
    x=row;
    y=col;
    while(y>=0 && x<n){
        if(board[x][y]=='Q') return false;
        y--;
        x++;
    }
    return true;
}
void solve(vector<string> &board,vector<vector<string>> &ans,int n,int col){
    if(col==n){
        ans.push_back(board);
        return ;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(board,ans,n,col+1);
            board[row][col]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i].push_back('.');
            }
        }
        solve(board,ans,n,0);
        return ans;
    }
};
