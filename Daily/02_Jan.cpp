// Partitioning Into Minimum Number Of Deci-Binary Numbers

class Solution {
public:
    int minPartitions(string n) {
        int maxi = INT_MIN;
        for(int i=0;i<n.length();i++){
            maxi = max(maxi,int(n[i]));
        }
        return maxi-48;
    }
};
