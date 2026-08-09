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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int,int>mp;
        for(int i =0; i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return tree(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,mp);
    }
    TreeNode* tree(vector<int>&inorder, int is,int ie, vector<int>&preorder,int ps,int pe,unordered_map<int,int>&mp)
    {
        if(is>ie || ps>pe)
        return NULL;
        TreeNode *root =new TreeNode(preorder[ps]);
        int inroot=mp[preorder[ps]];
        int leftlength=inroot-is;
        root->left=tree(inorder,is,inroot-1,preorder,ps+1,ps+leftlength,mp);
        root->right=tree(inorder,inroot+1,ie,preorder,ps+leftlength+1,pe,mp);
        return root;
    }
};