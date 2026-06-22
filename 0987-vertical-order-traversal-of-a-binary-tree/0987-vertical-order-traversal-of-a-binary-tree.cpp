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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        queue<pair<TreeNode* ,pair<int ,int>>> q;
        map<int , map<int , multiset<int>>> m;
        vector<vector<int>> vec;
        int v=0;
        int level=0;
        if(root==NULL)
        {
            return vec;
        }
        q.push({root,{v,level}});
        while(!q.empty())
        {
            int size= q.size();
            for (int i =0; i <size;i++)
            {
                auto element=q.front();
                q.pop();
                TreeNode* node = element.first;
                v=element.second.first;
                level=element.second.second;
                m[v][level].insert(node->val);
                if(node->left)
                {
                    q.push({node->left,{v-1,level+1}});
                }
                if(node->right)
                {
                    q.push({node-> right,{v+1, level+1}});
                }
            }
        }
        for(auto [col,element]:m)
        {
            vector <int> ve;
            for (auto [row,value]:element)
            {
                ve.insert(ve.end(),value.begin(),value.end());
            }
            vec.push_back(ve);
        }
        return vec;
    }
    

};