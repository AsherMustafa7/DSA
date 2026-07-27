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
        if(root==nullptr) return 0;
        int l =lpp(root);
        int r =rpp(root);
        if(l==r){
            return pow(2,l) -1 ;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int lpp(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=1+lpp(root->left);  
        return l;
    }
    int rpp(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int r=1+rpp(root->right);  
        return r;
    }
};