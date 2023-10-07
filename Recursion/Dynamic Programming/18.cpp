// Russian Doll Envelopes


class Solution {
public:
static bool cmp(vector<int> &a,vector<int> &b){
    if(a[0]==b[0]) return a[1]>b[1];
    else return a[0]<b[0];
}
int solve(int n,vector<vector<int>>& en){
    if(n==0) return 0;
    vector<int> ans;
    ans.push_back(en[0][1]);
    for(int i=1;i<n;i++){
        if(en[i][1] > ans.back())
        ans.push_back(en[i][1]);
        else{
            int index = lower_bound(ans.begin(),ans.end(),en[i][1])-ans.begin();
            ans[index] = en[i][1];
        }
    }
    return ans.size();
}
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),cmp);
        return solve(n,envelopes);
    }
};
