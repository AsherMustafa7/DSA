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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL) return 0;
        int maxi=0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,1});
        while(!q.empty())
        {
            int n =q.size();
            long long minid = q.front().second;
            long long left;
            long long right;
            for(int i =0; i <n;i++)
            {
                auto p=q.front();
                TreeNode * node=p.first;
                long long val=p.second - minid;
                q.pop();
                if(i==0)
                {
                    left=val;
                }
                if(i==n-1)
                {
                    right=val;
                }
                if(node->left)
                {
                    q.push({node->left,2*val});
                }
                if(node->right)
                {
                    q.push({node->right,2*val+1});
                }
            }
            int width=right-left+1;
            maxi=max(maxi,width);
        }

        return (int)maxi;
    }
};