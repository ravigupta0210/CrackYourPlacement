// Word Search


class Solution {
public:
bool search(int i,int j,string word,vector<vector<char>>& board, int index){
    if(index == word.size()) return true;
    if(i<0 || j<0 || i>= board.size() || j>=board[0].size()) return false;
    bool ans=false;
    if(board[i][j] == word[index]) { board[i][j]='*';
    ans=search(i+1,j,word,board,index+1) || search(i-1,j,word,board,index+1) || search(i,j+1,word,board,index+1) || search(i,j-1,word,board,index+1);
    board[i][j] = word[index];
    }
    return ans;

}
    bool exist(vector<vector<char>>& board, string word) {
        //in this problem we find word only and go through this by backtracking and dfs
        int n=board.size();
        int m=board[0].size();
        int index=0;
        bool ans=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[index]){
                    if(search(i,j,word,board,index))
                    return true;
                }
            }
        }
        return ans;
//here we mistake in taking n,m;
    }
};
