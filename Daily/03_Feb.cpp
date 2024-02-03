// Sliding Window Maximum


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(int i=0;i<k;i++)
        pq.push({nums[i],i});

        ans.push_back(pq.top().first);
        for(int i=k;i<n;i++){
            pq.push({nums[i],i});
            while(!pq.empty() && pq.top().second <= i-k)
            pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};


// Min Stack


class MinStack {
public:
vector<pair<int,int>> vec;
    MinStack() {
        
    }
    
    void push(int val) {
        pair<int,int> p;
        p.first = val;
        if(vec.size()==0)
        p.second = val;
        else p.second = min(val,vec.back().second);
        vec.push_back(p);
    }
    
    void pop() {
        vec.pop_back();
    }
    
    int top() {
        return vec.back().first;
    }
    
    int getMin() {
        return vec.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



// Rotting Oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        queue<pair<int,int>> q;
        int row=grid.size(),col = grid[0].size(),ans=0;

        bool check=true;
        for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        if(grid[i][j]==1 || grid[i][j]==2) check = false;

        if(check) return 0;

        for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        if(grid[i][j]==2)
        q.push({i,j});

        while(!q.empty()){
            int size=q.size();
            ans++;
            
            while(size--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int index=0;index<4;index++){
                    int x=i+dx[index];
                    int y=j+dy[index];
                    if(x>=0 && x<row && y>=0 && y<col && grid[x][y]==1){
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                }
            }
        }
        for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        if(grid[i][j]==1) return -1;
        
        return ans-1;
    }
};
