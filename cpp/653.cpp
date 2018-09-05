//653. Two Sum IV - Input is a BST
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
    void in_order(TreeNode* root, vector<int> &list)
    {
        if(root != NULL)
        {
            in_order(root->left, list);
            list.push_back(root->val);
            in_order(root->right, list);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
            return false;
        vector<int> list;
        in_order(root, list);
        int left = 0, right = list.size()-1, sum=0;
        while(left<right)
        {
            sum = list[left] + list[right];
            if(sum<k)
                left++;
            else if(sum>k)
                right--;
            else
                return true;
        }
        return false;
    }
    
};
