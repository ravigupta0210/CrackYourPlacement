// M-Coloring Problem


class Solution{
public:
static const int N=101;
bool safe(bool graph[N][N],int i, int x, int n,vector<int>&col){
    for(int z=0;z<n;z++){
        if(graph[i][z]==1 && col[z]==x)
        return false;
        
    }
    return true;
}
bool solve(bool graph[N][N],int i, int m, int n,vector<int>&col){
    if(i==n) return true;
    for(int x=0;x<m;x++){
        if(safe(graph,i,x,n,col)){
            col[i]=x;
            if(solve(graph,i+1,m,n,col)) return true;
            col[i]=-1;
        }
    }
    return false;
}
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> col(n,-1);
        return solve(graph,0,m,n,col);
    }
};
