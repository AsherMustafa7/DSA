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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {

        vector<vector<int>> vec;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
         if(root==NULL)
        {
            return vec;
        }
        q.push(root);
        int f = 1;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>v;
            for(int i =0; i <n; i++)
            {
                TreeNode* newnode=q.front();
                v.push_back(newnode->val);
                q.pop();
                if(newnode->left) q.push(newnode->left);
                if(newnode->right) q.push(newnode->right);
            }
            vec.push_back(v);
        }
        for(int i=0; i <vec.size();i++)
        {
            vector<int>temp;
            if(f==1)
            {
                for(int j=0; j<vec[i].size();j++)
                {
                    temp.push_back(vec[i][j]);
                }
                f=0;
            }
            else
            {
                for(int j=vec[i].size()-1;j>=0;j--)
                {
                    temp.push_back(vec[i][j]);
                }
                f=1;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};