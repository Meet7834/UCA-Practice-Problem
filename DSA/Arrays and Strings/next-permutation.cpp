class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) return;
        int breakPoint = -1;
        for (int i=nums.size()-2; i >=0; i--){
            if ( nums[i] < nums[i+1]){
                breakPoint = i;
                break;
            }
        }
        if (breakPoint == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int nextSmallest = -1;
        for (int i=nums.size()-1; i> breakPoint; i--){
            if (nums[breakPoint] < nums[i]){
                nextSmallest = i;
                break;
            }
        }
        swap(nums[breakPoint], nums[nextSmallest]);

        reverse(nums.begin()+ breakPoint + 1, nums.end());

    }
};