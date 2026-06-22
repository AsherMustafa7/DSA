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
    bool isSymmetric(TreeNode* root) {
        map<int, vector<string>> m;
        cal(root,0,m);
        return pal(m);
    }
    void cal(TreeNode* node, int r, map<int,vector<string>>&m)
    {
        if(node == NULL)
        {
            m[r].push_back("N");
            return;
        }
        
        m[r].push_back(to_string(node->val));
        cal(node->left,r+1,m);
        cal(node->right,r+1,m); 
    }
    bool pal(map<int,vector<string>>&m)
    {
        //cheak for each int of m , if the string i palandrome
        for(auto x : m)
    {
        vector<string> v = x.second;

        int i = 0;

        int j = v.size() - 1;

        while(i < j)
        {
            if(v[i] != v[j])
                return false;

            i++;
            j--;
        }
    }

    return true;

    }
};