class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            int left = i + 1, right = nums.size() - 1;

            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) left++;
                else if (sum > 0) right--;
                else if (sum == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});

                    int lastLeft = nums[left], lastRight = nums[right];
                    while(left < right && nums[left] == lastLeft) ++left;
                    while(left < right && nums[right] == lastRight) --right;
                }
            }
        }
        return ans;
    }
};