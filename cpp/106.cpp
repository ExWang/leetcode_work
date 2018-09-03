//106. Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode *build(vector<int> &post, int pl, int pr,
                   vector<int> &in, int il, int ir) {
        if (pl > pr || il > ir) {
            return NULL;
        }
        
        int iroot = ir;
        while (in[iroot] != post[pr]) {
            iroot--;
        }
        TreeNode *root = new TreeNode(post[pr]);
        root->left = build(post, pl, pl + (iroot - il) - 1, in, il, iroot - 1);
        root->right = build(post, pl + (iroot - il), pr - 1, in, iroot + 1, ir);
        return root;
    }        
};
