// Rat in a Maze Problem - I



class Solution{
    public:
    bool isPossible(int x,int y,vector<vector<int>> visited,vector<vector<int>> &m,int n){
        if(x>=0 && x<n && y>=0 && y<n && m[x][y]==1 && visited[x][y]!=1)
        return true;
        else return false;
    }
    void solve(vector<string> &ans,string path,int x,int y,vector<vector<int>> &m,int n,vector<vector<int>> visited){
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return ;
        }
        visited[x][y] = 1;
        int newx=x+1;
        int newy=y;
        if(isPossible(newx,newy,visited,m,n)){
            path.push_back('D');
            solve(ans,path,newx,newy,m,n,visited);
            path.pop_back();
        }
        newx=x-1;
        newy=y;
        if(isPossible(newx,newy,visited,m,n)){
            path.push_back('U');
            solve(ans,path,newx,newy,m,n,visited);
            path.pop_back();
        }
         newx=x;
         newy=y+1;
        if(isPossible(newx,newy,visited,m,n)){
            path.push_back('R');
            solve(ans,path,newx,newy,m,n,visited);
            path.pop_back();
        }
         newx=x;
         newy=y-1;
        if(isPossible(newx,newy,visited,m,n)){
            path.push_back('L');
            solve(ans,path,newx,newy,m,n,visited);
            path.pop_back();
        }
        visited[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0] == 0) return ans;
        int x=0,y=0;
        vector<vector<int>> visited = m;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        visited[i][j] = 0;
        
        string path ="";
        solve(ans,path,x,y,m,n,visited);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
