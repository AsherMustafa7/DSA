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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        if(root==NULL)
        return vec;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n= q.size();
            
            for(int i =0; i <n;i++)
            {  
                TreeNode* newnode=q.front();
                if(i==0)vec.push_back(newnode->val);
                q.pop();
                if(newnode->right) q.push(newnode->right);
                if(newnode->left) q.push(newnode->left);
            }
        }
        return vec;
    }
};