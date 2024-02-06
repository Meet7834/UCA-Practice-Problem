class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int occ[256] = { 0 };
        int l = 0, r = 0, ans = 0;
        while(r < s.length()){
            occ[s[r]]++;
            while(occ[s[r]] > 1) occ[s[l++]]--;
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};