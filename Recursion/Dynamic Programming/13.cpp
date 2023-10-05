// Ninja's Trip



int solve(int n, vector<int> &days, vector<int> &cost,int index,vector<int> &dp){
    if(index>=n) return 0;
    
    if(dp[index]!=-1) return dp[index];
    //0 days
    int option1 = cost[0]+solve(n,days,cost,index+1,dp);
    
    //7 days
    int i;
    for( i=index;i<n && days[i]< days[index]+7 ; i++);
    int option2 = cost[1]+solve(n,days,cost,i,dp);
    
    //30 days
    for( i=index;i<n && days[i]< days[index]+30 ; i++);
    int option3 = cost[2]+solve(n,days,cost,i,dp);
    
    return dp[index]=min(option1,min(option2,option3));
}

int solveTab(int n, vector<int> &days, vector<int> &cost){
    vector<int> dp(n+1,0);
    dp[n] = 0;
    for(int index = n-1;index >=0 ;index--){
        
        //0 days
        int option1 = cost[0]+dp[index+1];
        
        //7 days
        int i;
        for( i=index;i<n && days[i]< days[index]+7 ; i++);
        int option2 = cost[1]+dp[i];
        
        //30 days
        for( i=index;i<n && days[i]< days[index]+30 ; i++);
        int option3 = cost[2]+dp[i];
        
        dp[index]=min(option1,min(option2,option3)); 
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // vector<int> dp(n+1,-1);
    // return solve(n,days,cost,0,dp);
    // return solveTab(n,days,cost);
    
    queue<pair<int,int>> month, week;
    int ans = 0;
    for(int day:days){
        while(!week.empty() && week.front().first+7 <= day)
        week.pop();
        while(!month.empty() && month.front().first+30 <= day)
        month.pop();
        week.push(make_pair(day,ans+cost[1]));
        month.push(make_pair(day,ans+cost[2]));
        
        ans = min(ans+cost[0],min(week.front().second,month.front().second));
    }
    return ans;

    
    
}
