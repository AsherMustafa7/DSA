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
    int maxPathSum(TreeNode* root) 
    {
        int maxi=INT_MIN;
        int p=find(root,maxi);
        return maxi;
    }
    int find(TreeNode* root, int &maxi)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=find(root->left,maxi);
        int right=find(root->right,maxi);
        maxi=max(maxi,root->val+left+right);
        maxi=max(maxi,root->val);
        maxi=max(maxi,root->val+left);
        maxi=max(maxi,root->val+right);
        return max(root->val,root->val+max(left,right));
    }
};