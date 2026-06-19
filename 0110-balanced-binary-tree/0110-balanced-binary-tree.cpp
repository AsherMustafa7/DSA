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
    bool isBalanced(TreeNode* root) {
        // The intution here is that the height(left)- height(right)<=1
        // thats a balanced binary tree.
        int flag=1;
        cal(root,flag);
        if(flag==1)
        {
            return true;
        }
        else return false;
    }
    int cal (TreeNode* root, int &flag)
    {
        if(root==NULL || flag==0)
        {
            return 0;
        }
        int lh=cal(root->left,flag);
        int rh= cal(root->right,flag);
        if(abs(lh-rh) >1)
        {
            flag =0;
        }
        return 1+max(lh,rh);
    }
};