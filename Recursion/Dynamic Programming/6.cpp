// Cut Into Segments


#include<bits/stdc++.h>
int solve(int n,int x,int y,int z,vector<int> &dp){
	if(n==0) return 0;
	if(n<0) return INT_MIN;
	if(dp[n]!=-1) return dp[n];
	return dp[n]= max(1+solve(n-x,x,y,z,dp),max(1+solve(n-y,x,y,z,dp),1+solve(n-z,x,y,z,dp)));
}
int solve2(int n,int x,int y,int z){
	vector<int> dp(n+1,INT_MIN);
	dp[0]=0;
	for(int i=1;i<=n;i++){
	if(i-x >= 0)
	dp[i]=max(dp[i],dp[i-x]+1);

	if(i-y >= 0)
	dp[i]=max(dp[i],dp[i-y]+1);

	if(i-z >= 0)
	dp[i]=max(dp[i],dp[i-z]+1);
	}
	return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	// vector<int> dp(n+1,-1);
	// int ans= solve(n,x,y,z,dp);
	int ans=solve2(n,x,y,z);
	if(ans<0) return 0;
	else return ans;
	// if(ans<0) return 0;
	// else return ans;
}
