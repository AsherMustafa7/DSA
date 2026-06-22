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
        for(auto [col,element]:
        m)
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



// There is also a recursive solution
/*
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    // Helper function tracking both column (c) and row/depth (r)
    void cal(TreeNode* root, map<int, map<int, multiset<int>>> &m, int c, int r) {
        if (root == NULL) {
            return;
        }
        
        // Insert the value into the specific column and row
        m[c][r].insert(root->val);
        
        // Traverse left (col - 1, row + 1) and right (col + 1, row + 1)
        cal(root->left, m, c - 1, r + 1);
        cal(root->right, m, c + 1, r + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map structure: Column -> Row -> Sorted Values
        map<int, map<int, multiset<int>>> m;
        vector<vector<int>> vec;
        
        // Call the helper function to populate the map
        cal(root, m, 0, 0);
        
        // Extract data from the nested map into the final vector
        for (const auto& [col, rowMap] : m) {
            vector<int> colValues;
            for (const auto& [row, values] : rowMap) {
                // Insert all sorted values from this row into the column vector
                colValues.insert(colValues.end(), values.begin(), values.end());
            }
            vec.push_back(colValues);
        }
        
        return vec;
    }
};

*/