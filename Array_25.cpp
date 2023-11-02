// Max Value of Equation


class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // int n=points.size();
        // int sum=INT_MIN;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(abs(points[j][0] - points[i][0] ) <= k){
        //             sum=max(sum, points[i][1] + points[j][1] + abs(points[j][0] - points[i][0]) );
                    
        //         }
        //     }
        // }
        // return sum;
    //give tle



    //priority_queue
    priority_queue<pair<int,int>> pq;
    int ans=INT_MIN;
    for(int i=0;i<points.size();i++){
        while(!pq.empty() && points[i][0] - pq.top().second > k) pq.pop();
        if(!pq.empty()){
            ans=max(ans, points[i][1]+pq.top().first+points[i][0]);

        }
        pq.push({points[i][1]-points[i][0],points[i][0]});
    }
return ans;

    }
};
