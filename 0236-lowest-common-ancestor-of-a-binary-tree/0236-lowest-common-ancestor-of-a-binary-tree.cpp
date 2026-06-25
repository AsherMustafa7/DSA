/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1;
        vector <TreeNode*> v2;
        bool b1=check(root,v1,p);
        bool b2=check(root,v2,q);
        if(!b1 || !b2)
        {
            return NULL;
        }
        TreeNode* val;
        for(int i=0; i <min(v1.size(),v2.size());i++)
        {
            if(v1[i]->val==v2[i]->val)
            {
                val=v1[i];
            }
            else
            break;
        }
        return val;
    }
    bool check(TreeNode* root,vector<TreeNode*>&v,TreeNode* f)
    {
        if(root==NULL)
        {
            return false;
        }
        v.push_back(root);
        if(root==f)
        {
            return true;
        }
        if(check(root->left,v,f))
        {
            return true;
        }
        if(check(root->right, v, f))
        {
            return true;
        }
        v.pop_back();
        return false;
    }
};