//198. House Robber
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        else if(nums.size()==2)
            return max(nums[0],nums[1]);
        else if(nums.size()==3)
            return max(nums[0]+nums[2],nums[1]);
        int max_money = 0;
        int tmp = 0;
        int prev = 0;
        for(int i=0; i<nums.size(); i++)
        {
            tmp = prev;
            prev = nums[i] + max_money;
            max_money = max(max_money, tmp);
        }
        max_money = max(max_money, prev);
        return max_money;
    }
};
