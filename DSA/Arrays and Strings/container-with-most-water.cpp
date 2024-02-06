class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, left = 0, right = height.size() - 1;
        while(left < right){
            maxArea = max(maxArea, (right - left) * min(height[left], height[right]));
            if (height[left] > height[right]) right--;
            else left++;
        }
        return maxArea;
    }
};