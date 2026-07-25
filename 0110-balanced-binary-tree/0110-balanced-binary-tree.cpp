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
    bool isBalanced(TreeNode* root) 
    {
        bool flag=true;
        int h=checkb(root,flag);
        
        return flag;
    }
    int checkb(TreeNode* root, bool &flag)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l= 1+checkb(root->left,flag);
        int r= 1+checkb(root->right,flag);
        if(abs(l - r) > 1)
        flag=false;
        return max(l,r);
    }
};