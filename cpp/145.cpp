//145. Binary Tree Postorder Traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Note for postorder travelsal
// Left Tree -----> Right Tree -----> Root
class Solution {
public:
    void myfn(TreeNode* root, vector<int>&res)
    {
        if(root->left!=NULL)
            myfn(root->left, res);
        if(root->right!=NULL)
            myfn(root->right, res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res = {};
        if(root!=NULL)
            myfn(root, res);
        return res;
    }
};
