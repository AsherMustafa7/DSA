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
    int kthSmallest(TreeNode* root, int k) 
    {
        int count=0;
        int val=-1;
        inorder(root,count,val,k);
        return val;
    }
    void inorder(TreeNode* root, int &count,int &val,int &k)
    {
        if(root==NULL) return;
        
        inorder(root->left,count,val,k);
        count++;
        if(count==k)
        {
            val=root->val;
            return;
        }
        inorder(root->right,count,val,k);
    }
};