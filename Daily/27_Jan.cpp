// M-Coloring Problem


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    static const int N=101;
    bool safe(bool graph[N][N],int x,int n,int i,vector<int> &col){
        for(int z=0;z<n;z++){
            if(graph[i][z]==1 && col[z] == x)
            return false;
        }
        return true;
    }
    bool solve(bool graph[N][N],int m,int n,int i,vector<int> &col){
        if(i==n){
            return true;
        }
        for(int x=0;x<m;x++){
            if(safe(graph,x,n,i,col)){
                col[i]=x;
                if(solve(graph,m,n,i+1,col)) return true;
                col[i]=-1;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> col(n,-1);
        return solve(graph,m,n,0,col);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


// Rat in a Maze Problem - I


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int n,vector<vector<int>> &m,vector<vector<bool>> &v,int x,int y){
        if(x>=0 && x<n && y>=0 && y<n && v[x][y]!=1 && m[x][y]==1) return true;
        return false;
    }
    void solve(vector<vector<bool>> &v,int n,vector<vector<int>> &m,int x,int y,string path,vector<string> &ans){
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return ;
        }
        v[x][y]=1;
        if(isSafe(n,m,v,x+1,y))
        solve(v,n,m,x+1,y,path+'D',ans);
        if(isSafe(n,m,v,x-1,y))
        solve(v,n,m,x-1,y,path+'U',ans);
        if(isSafe(n,m,v,x,y+1))
        solve(v,n,m,x,y+1,path+'R',ans);
        if(isSafe(n,m,v,x,y-1))
        solve(v,n,m,x,y-1,path+'L',ans);
        v[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0]==0) return ans;
        string path="";
        vector<vector<bool>> v(n,vector<bool>(n,0));
        solve(v,n,m,0,0,path,ans);
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
