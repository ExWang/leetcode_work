//105. Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)
            return NULL;
        stack<int> val_s;
        stack<TreeNode *> tree_s;
        TreeNode *t, *r, *root;
        int i, j, right_flag;
        
        i = 1;
        j = right_flag = 0;
        val_s.push(preorder[0]);
        
        root = new TreeNode(preorder[0]);
        tree_s.push(root);
        t = root;
        
        while(i<preorder.size())
        {
            if(!tree_s.empty() && tree_s.top()->val==inorder[j])
            {
                t = tree_s.top();
                tree_s.pop();
                val_s.pop();
                right_flag=1;
                j++;
            }
            else
            {
                if(right_flag==0)
                {
                    val_s.push(preorder[i]);
                    t -> left = new TreeNode(preorder[i]);
                    t = t -> left;
                    tree_s.push(t);
                    i++;
                 }
                 else 
                 {
                    right_flag = 0;
                    val_s.push(preorder[i]);
                    t -> right = new TreeNode(preorder[i]);
                    t = t -> right;
                    tree_s.push(t);
                    i++;
                 }
            }
            
        }
        return root; 
    }
};
