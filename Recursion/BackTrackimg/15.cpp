// Find Minimum Time to Finish All Jobs


class Solution {
public:
void solve(int i,int n,int k,vector<int>& jobs,vector<int>& work,int &ans){
    if(i==n){
        ans = min(*max_element(work.begin(),work.end()),ans);
        return ;
    }
    if(*max_element(work.begin(),work.end()) >= ans) return ;
    for(int j=0;j<k;j++){
        if(j>0 && work[j]==work[j-1]) continue;
        work[j]+=jobs[i];
        solve(i+1,n,k,jobs,work,ans);
        work[j]-=jobs[i];
    }
}
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(),jobs.end(),greater<int>());
        int n=jobs.size();
        if(n==k) return jobs[0];
        int index=0;
        int ans=INT_MAX;
        vector<int>work(k,0);
        solve(index,n,k,jobs,work,ans);
        return ans;
    }
};
