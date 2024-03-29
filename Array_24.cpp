// Game of Life


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
       int row=board.size();
       int col=board[0].size();
       vector<vector<int>> grid=board;
       for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
               int live=0,dead=0;
               if(i-1 >=0 && j-1 >= 0){
                   if(board[i-1][j-1] == 0) dead++;
                   else live++;
               }

               if(i-1 >=0 ){ 
                   if(board[i-1][j] == 0) dead++;
                   else live++;
               }

               if(i-1 >=0 && j+1 < col){
                   if(board[i-1][j+1] == 0) dead++;
                   else live++;
               }

               if(j+1 < col){
                   if(board[i][j+1] == 0) dead++;
                   else live++;
               }

               if(i+1 < row && j+1 < col){
                   if(board[i+1][j+1] == 0) dead++;
                   else live++;
               }

               if(i+1 < row ){
                   if(board[i+1][j] == 0) dead++;
                   else live++;
               }

               if(i+1 < row && j-1 >=0){
                   if(board[i+1][j-1] == 0) dead++;
                   else live++;
               }

               if(i >= 0 && j-1 >= 0){
                   if(board[i][j-1] == 0) dead++;
                   else live++;
               }
               if(board[i][j] == 1){
                   if(live<2) grid[i][j]=0;
                   if(live==2 || live==3) grid[i][j]=1;
                   if(live>3) grid[i][j]=0;
               }
               else if(board[i][j] == 0){
                   if(live == 3) grid[i][j]=1;
               }
               else{
                   grid[i][j] = board[i][j];
               }
           }

       }
       board=grid; 
    }
};
