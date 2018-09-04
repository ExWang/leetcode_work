//102. Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> fin_res;
        if(root==NULL)
            return fin_res;
        queue<TreeNode* > tree_que;
        tree_que.push(root);
        while(!tree_que.empty())
        {
            int now_layer_num = tree_que.size();
            vector<int> tmp_vec;
            for(int i=0; i<now_layer_num; i++)
            {
                TreeNode* tmp_node = tree_que.front();
                tmp_vec.push_back(tmp_node->val);
                tree_que.pop();
                if(tmp_node->left)
                    tree_que.push(tmp_node->left);
                if(tmp_node->right)
                    tree_que.push(tmp_node->right);
            }
            fin_res.push_back(tmp_vec);
        }
        return fin_res;
    }
};
