// Rat in a Maze Problem - I



//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int newx,int newy,vector<vector<bool>> &visited,vector<vector<int>> &m,int n){
        if((newx>=0 && newx<n) && (newy>=0 && newy<n) && (visited[newx][newy]==0) && (m[newx][newy] == 1)){
            return true;
        }
        else return false;
    }
    void solve(vector<vector<int>> &m, int n,string path,int x,int y,vector<string> &ans,vector<vector<bool>> &visited){
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return ;
        }
        visited[x][y]=1;
        //down
        if(isSafe(x+1,y,visited,m,n)){
            solve(m,n,path+'D',x+1,y,ans,visited);
        }
        //left
        if(isSafe(x,y-1,visited,m,n)){
            solve(m,n,path+'L',x,y-1,ans,visited);
        }
        if(isSafe(x-1,y,visited,m,n)){
            solve(m,n,path+'U',x-1,y,ans,visited);
        }
        if(isSafe(x,y+1,visited,m,n)){
            solve(m,n,path+'R',x,y+1,ans,visited);
        }
        visited[x][y]=0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string path="";
        if(m[0][0] == 0) return ans;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        solve(m,n,path,0,0,ans,visited);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
