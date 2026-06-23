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
class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        int count =0;
        int ans=-1;
        cheak(root,k,count, ans);
        return ans;
    }
    void cheak(TreeNode* root,int k,int &count, int &ans)
    {
        if(root==NULL||ans!=-1)
        {
            return;
        }
        cheak(root->left,k,count,ans);
        count++;
        if(count==k)
        {
            ans=root->val;
            return;
        }
        cheak(root->right,k,count, ans);
    }
};