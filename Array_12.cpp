// Container With Most Water


class Solution {
public:
    int maxArea(vector<int>& height) {
        //here approach is simple that we cal only area and compare with other areas and give maximum
        //two pointer approach
        int left=0,right=height.size()-1;
        int maxArea=0;
        while(left<=right){
            int currentArea=min(height[left],height[right])*(right-left);
            maxArea=max(currentArea,maxArea);
            if(height[left] < height[right])
            left++;
            else right--;
        }
        return maxArea;
    }
};
