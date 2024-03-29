// Maximum Points You Can Obtain from Cards


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //here our approach is simple 
        //we solve this by window of size of k
        int res=0;
        //here we mistake in index
        for(int i=0;i<k;i++) res+=cardPoints[i];
        int n=cardPoints.size();
        int curr=res;
        for(int i=k-1;i>=0;i--){
            curr-=cardPoints[i];
            curr+=cardPoints[n-k+i];
            res=max(res,curr);
        }
        return res;
    }
};
