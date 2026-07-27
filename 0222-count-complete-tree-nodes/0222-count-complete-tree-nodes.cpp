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
        int count=0;
        cnt( root,count);
        return count;
    }
    void cnt(TreeNode* root, int & count)
    {
        if(root==NULL)
        {
            return;
        }
        count++;
        cnt(root->left,count);
        cnt(root->right,count);
    }
};