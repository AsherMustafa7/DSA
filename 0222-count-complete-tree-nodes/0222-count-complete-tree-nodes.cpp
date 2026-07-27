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
    int countNodes(TreeNode* root) 
    {
        int flag=0;
        int n=cnt( root);
        return n;
        
    }
    int cnt(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=cnt(root->left);
        int r=cnt(root->right);
        return 1+l+r;
    }
};