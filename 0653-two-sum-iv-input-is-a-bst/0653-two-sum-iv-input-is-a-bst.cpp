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
    bool findTarget(TreeNode* root, int k) 
    {
        unordered_map<int,int>mp;
        return find(root,k,mp);
    }
    bool find(TreeNode* root,int &k,unordered_map<int,int>&mp)
    {
        if(root==NULL)
        {
            return false;
        }
        if(mp.find(k-(root->val))!=mp.end())
        {
            return true;
        }
        else
        {
            mp[root->val]=1;
        }
        if(find(root->left,k,mp)||find(root->right,k,mp))return true;
        return false;
    }
};