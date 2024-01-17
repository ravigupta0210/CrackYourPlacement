// Search a 2D Matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0;
        int end = row*col-1;
        

        while(start <= end){
            int middle=start+(end-start)/2 ;
            int element = matrix[middle/col][middle%col];
            if(target == element) return 1;
            else if(target < element)
            end = middle-1;
            else start = middle+1;
        }
        return 0;
    }
};
