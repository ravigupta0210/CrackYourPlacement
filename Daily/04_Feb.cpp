// The Celebrity Problem


#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
	stack<int> s;
 	for(int i=0;i<n;i++){
		 s.push(i);
	 }
	 while(s.size()>1){
		 int a=s.top();
		 s.pop();
		 int b=s.top();
		 s.pop();
		 if(knows(a,b))
		 s.push(b);
		 else
		 s.push(a);
	 }
	 int ans=s.top();

	 int zero=0,ones=0;

	 for(int i=0;i<n;i++){
		 if(M[ans][i]==0)
		 zero++;
		 if(M[i][ans]==1)
		 ones++;
	 }
	 if(zero!=n || ones!=n-1) return -1;
	 else return ans;
}


// Maximum of minimum for every window size


#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> arr, int n) {
    vector<int> left(n,0), right(n,0);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            if(s.empty()) left[i] = -1;
            else left[i] = s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop(); 
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            if(s.empty()) right[i] = n;
            else right[i] = s.top();
            s.push(i);
        }
        vector<int> ans(n,INT_MIN);
        for(int i=0;i<n;i++){
            int winSize = right[i]-left[i]-2;
            ans[winSize] = max(ans[winSize],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            ans[i] = max(ans[i],ans[i+1]);
        }
        return ans;
}


// Sliding Window Maximum


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<nums.size();i++){
            while(!dq.empty() && dq.front()==i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
