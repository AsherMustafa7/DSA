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

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi= 0;
        int height =cal(root, maxi);
        return maxi;
    }
    int cal(TreeNode* root,int &maxi)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh= cal(root->left,maxi);
        int rh = cal(root->right,maxi);
        maxi= max(maxi,lh+rh);// Remember we are giving not the height, we are giving the width , so look at the Node 1 , the left height is 2 the right is 1, so lh+rh =2+1.
        return 1+max(lh,rh);
    }
    
};