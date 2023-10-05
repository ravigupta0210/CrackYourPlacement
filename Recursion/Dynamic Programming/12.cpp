// Get Minimum Squares


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int solve(int n,vector<int> &dp){
	    if(n==0) return 0;
	    if(dp[n]!=-1) return dp[n];
	    int ans = n;
	    for(int i=1;i*i<=n;i++){
	        int temp = i*i;
	        ans = min(ans,1+solve(n-temp,dp));
	    }
	    return dp[n]=ans;
	}
	
	int solveTab(int n){
	    
	    vector<int> dp(n+1,INT_MAX);
	    dp[0] = 0;
	    for(int j=1;j<=n;j++){
	        int ans = j;
	    for(int i=1;i*i<=j;i++){
	        int temp = i*i;
	        ans = min(ans,1+dp[j-temp]);
	    }
	    dp[j]=ans;
	    }
	    
	   return dp[n];
	}
	
	int MinSquares(int n)
	{
	   // vector<int> dp(n+1,-1);
	   // return solve(n,dp);
	   return solveTab(n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
