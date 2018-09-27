//124.Binary Tree Maximum Path Sum
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        sumer(root, ans);
        return ans;
    }
    int sumer(TreeNode* root, int &sum)
    {
        if(!root)
            return 0;
        int L = sumer(root->left, sum);
        int R = sumer(root->right, sum);
        sum = max(L+R+root->val, sum);
        return max(0, max(L,R)+root->val);
    }
};
