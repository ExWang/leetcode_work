//543. Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        int fin_depth = 0;
        calDepth(root, fin_depth);
        return fin_depth;
    }
    
    int calDepth(TreeNode* root, int &depth){
        int L = 0, R = 0;
        if(root==NULL)
            return 0;
        if(root->left) 
            L = calDepth(root->left, depth);
        if(root->right) 
            R = calDepth(root->right, depth);
        depth = max(L + R, depth);
        return max(L, R)+1;
    }
};
