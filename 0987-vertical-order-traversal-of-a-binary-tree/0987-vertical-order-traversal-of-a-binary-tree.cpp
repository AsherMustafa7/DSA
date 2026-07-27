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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        queue< pair<int,pair<int,TreeNode*>>>q;
        map<int,map<int, multiset<int>>>mp;
        q.push({0,{0,root}});
        while(!q.empty())
        {
            auto p=q.front();
            int level=p.first;
            int col=p.second.first;
            TreeNode* newnode=p.second.second;
            mp[col][level].insert(newnode->val);
            q.pop();
            if(newnode->left!=NULL)
            {
                q.push({level+1,{col-1,newnode->left}});
            }
            if(newnode->right!=NULL)
            {
                q.push({level+1,{col+1,newnode->right}});
            }
        }
        vector<vector<int>>vf;
        
        for(auto &col: mp)
        {
            vector<int>v;
            for(auto &row:col.second)
            {
                for(auto &val: row.second)
                {
                    v.push_back(val);
                }
            }
            vf.push_back(v);
        }
        return vf;
    }
};