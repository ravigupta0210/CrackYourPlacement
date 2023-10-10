// Minimum Swaps To Make Sequences Increasing


class Solution {
public:
int solve(vector<int>& num1, vector<int>& num2,int index,bool swapped,vector<vector<int>> &dp){
    if(index == num1.size()) return 0;

    if(dp[index][swapped] != -1) return dp[index][swapped];
    int ans = INT_MAX;
    int prev1 = num1[index-1];
    int prev2 = num2[index-1];

    if(swapped) swap(prev1,prev2);

    //noswap
    if(num1[index] > prev1 && num2[index] > prev2)
    ans= solve(num1,num2,index+1,0,dp);

    //swap
    if(num1[index] > prev2 && num2[index] > prev1)
    ans = min(ans,1+solve(num1,num2,index+1,1,dp));

    return dp[index][swapped] = ans;
}
// int solveTab(vector<int>& num1, vector<int>& num2,int n){
//     vector<vector<int>> dp(n+1,vector<int>(2,0));
//     for(int index = n-1;index>=1;index--){
//         for(int swapped = 1;swapped >= 0;swapped--){
//             int ans = INT_MAX;
//             int prev1 = num1[index-1];
//             int prev2 = num2[index-1];

//             if(swapped) swap(prev1,prev2);

//             //noswap
//             if(num1[index] > prev1 && num2[index] > prev2)
//             ans= dp[index+1][0];

//             //swap
//             if(num1[index] > prev2 && num2[index] > prev1)
//             ans = min(ans,1+dp[index+1][1]);

//             dp[index][swapped] = ans;
//         }
//     }
//     return dp[1][0];
// }

int solveTab(vector<int>& num1, vector<int>& num2,int n){
    int swap=0,noswap = 0,currSwap = 0,currNoSwap = 0;
    for(int index = n-1;index>=1;index--){
        for(int swapped = 1;swapped >= 0;swapped--){
            int ans = INT_MAX;
            int prev1 = num1[index-1];
            int prev2 = num2[index-1];

            if(swapped) {
                    int temp = prev2;
                    prev2 = prev1;
                    prev1 = temp; 
            }

            //noswap
            if(num1[index] > prev1 && num2[index] > prev2)
            ans= noswap;

            //swap
            if(num1[index] > prev2 && num2[index] > prev1)
            ans = min(ans,1+swap);
            
            if(swapped) currSwap = ans;
            else currNoSwap = ans;
        }
        swap = currSwap;
        noswap = currNoSwap;
    }
    return min(currSwap,currNoSwap);
}

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        int n = nums1.size();
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        bool swapped = 0;
        // return solve(nums1,nums2,1,swapped,dp);
        return solveTab(nums1,nums2,n);
    }
};
