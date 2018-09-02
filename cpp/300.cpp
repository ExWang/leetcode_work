//300. Longest Increasing Subsequence
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<=0)
            return 0;
        vector<int> dp(nums.size());
        dp[0] = 1;
        int max_len = 1;
        int tmp_len;
        for(int i=0; i<nums.size(); i++)
        {
            tmp_len = 0;
            for(int j=0; j<i; j++)
            {
                if(nums[i]>nums[j])
                {
                    tmp_len = max(tmp_len, dp[j]);
                }
            }
            dp[i] = tmp_len +1;
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};
