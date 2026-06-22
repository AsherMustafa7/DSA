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
        val(root,0,vec);
        return vec;
    }
    void val(TreeNode* node, int level, vector <int>&vec)
    {
        if(node==NULL)
        {
            return;
        }
        if(level==vec.size())
        {
            vec.push_back(node->val);
        }
        val(node->right, level+1,vec);
        val(node->left,level+1,vec);
    }
};