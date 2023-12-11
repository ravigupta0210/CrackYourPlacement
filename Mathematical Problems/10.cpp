// Max Points on a Line


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size(),ans=2;
        if(n <= 2) return n;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int curr=2;
                for(int k=2;k<n;k++){
                    if(k!=i && k!=j){
                        int x1 = points [i][0];
                        int y1 = points [i][1];
                        int x2 = points [j][0];
                        int y2 = points [j][1];
                        int x3 = points [k][0];
                        int y3 = points [k][1];
                        if((y2-y1)*(x2-x3) == (y2-y3)*(x2-x1)) curr++;
                    }
                    
                }
                ans = max(ans,curr);
            }
        }
        return ans;
    }
};
