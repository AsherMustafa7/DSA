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
    void flatten(TreeNode* root) 
    {
        vector<TreeNode*>v;
        pre(root,v);
        root=NULL;
        for(auto node:v)
        {
            if(root==NULL)
            {
                root=node;
                root->left=NULL;
            }
            else
            {
                root->right=node;
                root->left=NULL;
                root=root->right;
            }
        }
    }
    void pre(TreeNode* root, vector<TreeNode*>&v)
    {
        if(root==NULL)
        {
            return;
        }
        v.push_back(root);
        pre(root->left,v);
        pre(root->right,v);
    }
};