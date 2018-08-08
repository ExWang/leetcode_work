//90. Subsets II
class Solution {
public:
    void worker(vector<vector<int>> &res, vector<int> &tmp, vector<int> &nums,int startIndex)
    {
        res.push_back(tmp);
        for(int i=startIndex; i<nums.size(); i++)
        {
            if(i!=0 && nums[i]==nums[i-1] && i>startIndex) continue;
            tmp.push_back(nums[i]);
            worker(res, tmp, nums, i+1);
            tmp.pop_back();
            
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        worker(res, tmp, nums, 0);
        return res;
    }
};
