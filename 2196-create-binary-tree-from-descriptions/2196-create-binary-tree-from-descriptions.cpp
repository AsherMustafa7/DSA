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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_map<int, TreeNode*>mp;
        unordered_set<int> child;
        for(int i =0; i <descriptions.size();i++)
        {
            if(mp.find(descriptions[i][0])!=mp.end())
            {
                if(mp.find(descriptions[i][1])!=mp.end())
                {
                    TreeNode* outer=mp[descriptions[i][0]];
                    TreeNode* inner=mp[descriptions[i][1]];
                    child.insert(descriptions[i][1]);
                    mp[descriptions[i][1]]=inner;
                    if(descriptions[i][2]==1)
                    {
                        outer->left=inner;
                    }
                    else
                    {
                        outer->right=inner;
                    }
                }
                else
                {
                    TreeNode* outer=mp[descriptions[i][0]];
                    TreeNode* inner=new TreeNode(descriptions[i][1]);
                    mp[descriptions[i][1]]=inner;
                    child.insert(descriptions[i][1]);
                    if(descriptions[i][2]==1)
                    {
                        outer->left=inner;
                    }
                    else
                    {
                        outer->right=inner;
                    }
                }
            }
            else
            {
                TreeNode* newnode=new TreeNode(descriptions[i][0]);
                mp[descriptions[i][0]]=newnode;
                if(mp.find(descriptions[i][1])!=mp.end())
                {
                    TreeNode* inner=mp[descriptions[i][1]];
                    mp[descriptions[i][1]]=inner;
                    child.insert(descriptions[i][1]);
                    if(descriptions[i][2]==1)
                    {
                        newnode->left=inner;
                    }
                    else
                    {
                        newnode->right=inner;
                    }
                }
                else
                {
                    TreeNode* outer=mp[descriptions[i][0]];
                    TreeNode* inner=new TreeNode(descriptions[i][1]);
                    mp[descriptions[i][1]]=inner;
                    child.insert(descriptions[i][1]);
                    if(descriptions[i][2]==1)
                    {
                        outer->left=inner;
                    }
                    else
                    {
                        outer->right=inner;
                    }
                }
            }
        }
        for(auto &it : mp)
        {
            if(child.find(it.first) == child.end())
                return it.second;
        }
        return NULL;
    }
};