// 0 1 Knapsack



#include <bits/stdc++.h> 
int solve(vector<int> &weight, vector<int> &value, int index, int capacity,vector<vector<int>>& dp){
	if(index==0){
		if(weight[index]<=capacity){
			return value[0];
		}
		else return 0;
	}
	if(dp[index][capacity] != -1) return dp[index][capacity];
	int include = 0;
	if(weight[index]<=capacity)
	include = value[index]+solve(weight,value,index-1,capacity-weight[index],dp);
	int exclude = solve(weight,value,index-1,capacity,dp);
	
	return dp[index][capacity] = max(include,exclude);
}

int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity){
	vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));

		for(int i=weight[0];i<=capacity;i++){
			if(weight[0]<=capacity){
				dp[0][i] = value[0];
			}
			else dp[0][i] = 0;
		}

		for(int index = 1;index < n ;index++){
			for(int w = capacity;w>=0;w--){
					int include = 0;
					if(weight[index]<=w)
					include = value[index]+dp[index-1][w-weight[index]];
					int exclude = dp[index-1][w];
					
					dp[index][w] = max(include,exclude);
			}
		}
		return dp[n-1][capacity];
}


int solveSO(vector<int> &weight, vector<int> &value, int n, int capacity){
	vector<int> prev(capacity+1,0);
	vector<int> curr(capacity+1,0);

		for(int i=weight[0];i<=capacity;i++){
			if(weight[0]<=capacity){
				prev[i] = value[0];
			}
			else prev[i] = 0;
		}

		for(int index = 1;index < n ;index++){
			for(int w = capacity;w>=0;w--){
					int include = 0;
					if(weight[index]<=w)
					include = value[index]+prev[w-weight[index]];
					int exclude = prev[w];
					
					curr[w] = max(include,exclude);
			}
			prev = curr;
		}
		return prev[capacity];
}
int solveSOO(vector<int> &weight, vector<int> &value, int n, int capacity){
	
	vector<int> curr(capacity+1,0);

		for(int i=weight[0];i<=capacity;i++){
			if(weight[0]<=capacity){
				curr[i] = value[0];
			}
			else curr[i] = 0;
		}

		for(int index = 1;index < n ;index++){
			for(int w = capacity;w>=0;w--){
					int include = 0;
					if(weight[index]<=w)
					include = value[index]+curr[w-weight[index]];
					int exclude = curr[w];
					
					curr[w] = max(include,exclude);
			}
			
		}
		return curr[capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	// return solve(weight,value,n-1,maxWeight,dp);
	return solveSOO(weight,value,n,maxWeight);
}
