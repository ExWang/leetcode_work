//100. Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ret=true;
        if(p==NULL && q==NULL)
            return true;
        else if((p==NULL && q!=NULL) || (p!=NULL && q==NULL))
            return false;
        if(p->val != q->val)
            return false;
        if(p->left != NULL && q->left != NULL)
        {
            ret = isSameTree(p->left, q->left);
            if(ret==false)
                return false;
        }
        if(p->right != NULL && q->right != NULL)
        {
            ret = isSameTree(p->right, q->right);
            if(ret==false)
                return false;
        }
        if((p->left != NULL && q->left == NULL) || (p->left == NULL && q->left != NULL))
            return false;
        if((p->right != NULL && q->right == NULL) || (p->right == NULL && q->right != NULL))
            return false;
        return ret; 
    }
};
