// Steps by Knight



class Solution 
{
    public:
    bool isValid(int nrow,int ncol,int n){
        if(nrow>=1 && nrow<=n && ncol>=1 && ncol<=n) return true;
        else return false;
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    int visited[n+1][n+1] = {0};
	    int delRow[] = {-1,-1,1,1,-2,-2,2,2};
	    int delCol[] = {-2,2,-2,2,-1,1,-1,1};
	    visited[KnightPos[0]][KnightPos[1]]=1;
	    queue<pair<int,pair<int,int>>> q;
	    q.push({0,{KnightPos[0],KnightPos[1]}});
	    while(!q.empty()){
	        pair<int,pair<int,int>> front = q.front();
	        q.pop();
	        int ds = front.first, row = front.second.first, col = front.second.second;
	        if(row == TargetPos[0] && col == TargetPos[1]) return ds;
	        for(int i=0;i<8;i++){
	            int nrow = row+delRow[i], ncol = col+delCol[i];
	            if(isValid(nrow,ncol,n) && visited[nrow][ncol] != 1){
	                visited[nrow][ncol] = 1;
	                q.push({ds+1,{nrow,ncol}});
	            }
	        }
	    }
	    return -1;
	}
};
