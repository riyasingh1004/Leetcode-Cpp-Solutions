// Time Complexity O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max_sum;
    int max_gain(TreeNode* root) {
        
        if(!root)return 0;
        
        int l=max(max_gain(root->left),0);
        int r=max(max_gain(root->right),0);
        max_sum=max(max_sum,root->val+l+r);
        return root->val+max(l,r);
    }
    
    int maxPathSum(TreeNode* root) { 
       
       max_sum = INT_MIN;
       max_gain(root);
       return max_sum; 
    }
};