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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int maxi=0;
        findd(root,maxi);
        return maxi-2;
    }
    int findd(TreeNode* root,int &maxi)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l= 1+findd(root->left,maxi);
        int r=1+findd(root->right,maxi);
        maxi=max(maxi,l+r);
        return max(l,r);
    }
};