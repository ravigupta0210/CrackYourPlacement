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
