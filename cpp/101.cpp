//101. Symmetric Tree
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
    bool nextStep(TreeNode* left, TreeNode* right){
        bool ret=true;
        if(left->val != right->val)
            return false;
        if(left->left != NULL && right->right != NULL)
        {
            ret = nextStep(left->left, right->right);
            if(ret==false)
                return false;
        }
        if(left->right != NULL && right->left != NULL)
        {
            ret = nextStep(left->right, right->left);
            if(ret==false)
                return false;
        }
        if((left->right != NULL && right->left == NULL) || (left->right == NULL && right->left != NULL))
            return false;
        else if((left->left != NULL && right->right == NULL) || (left->left == NULL && right->right != NULL))
            return false;   
        return ret;
    }
    
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        if(root->left == NULL && root->right == NULL)
            return true;
        else if (root->left && root->right)
        {
            TreeNode* leftBranch = root->left;
            TreeNode* rightBranch = root->right;
            bool ret = nextStep(leftBranch, rightBranch);
            return ret;
        }
        else
        {
            return false;
        }
        
    }
};
