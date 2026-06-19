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
    int maxPathSum(TreeNode* root) 
    {
        
        int maxi=INT_MIN;
        cal(root,maxi);
        return maxi;
    }
    int cal(TreeNode* root, int &maxi)
    {
        if(root==NULL)
        {
            return 0;
        }
        /* you should know that when we write this  int lv = max(0,cal(root->left,maxi)); we are puring the -ve , values that are comming we are not taking it 
                50
            /       \
            20       40
                /         \
                -30       -20 
        
        the answer for this would eb 20+40+50. so we cant carry the -30 we instead we return 0 instead.
        
        
        */
        int lv = max(0,cal(root->left,maxi));
        int rv= max(0,cal(root-> right,maxi));
        maxi=max(maxi,root->val+lv+rv);
        return root->val+max(lv,rv);
    }
};