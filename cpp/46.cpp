//46. Permutations
class Solution {
public:

    void myfn(vector<vector<int>>&res, vector<int> subres, vector<int> nums){
        if(nums.size()==0)
            res.push_back(subres);
        else
            for(int i = 0; i<nums.size(); i++)
            {
                vector<int> perm(nums);
                subres.push_back(perm[i]);
                perm.erase(perm.begin()+i);
                myfn(res, subres, perm);
                subres.pop_back();
            }
    }
     
    vector<vector<int>> permute(vector<int>& nums) {        
        vector<vector<int>> res;
        vector<int> subres;
        if(nums.size()==0)
            return res;
        myfn(res, subres, nums);
        return res;
    }
};