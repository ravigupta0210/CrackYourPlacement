// Snakes and Ladders


class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        bool flag = true;
        int index=0;
        vector<int> flatten(n*n,-1);
        for(int i=n-1;i>=0;i--){
            if(flag){
                for(int j=0;j<n;j++)
                flatten[index++] = board[i][j];
            }
            else{
                for(int j=n-1;j>=0;j--)
                flatten[index++] = board[i][j];
            }
            flag=!flag;
        }

        vector<int> dist(n*n,-1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr == (n*n)-1) return dist[curr];
            for(int i=1;i<=6;i++){
                int next = curr+i;
                if(next >= n*n) continue;
                if(flatten[next]!=-1)
                next=flatten[next]-1;
                if(dist[next] == -1){
                    dist[next] = dist[curr]+1;
                    q.push(next);
                }
            }
        }
        return -1;
    }
};
