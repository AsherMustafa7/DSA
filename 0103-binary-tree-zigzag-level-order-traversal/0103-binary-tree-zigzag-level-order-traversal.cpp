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
        
        queue<TreeNode*> q;
         if(root==NULL)
        {
            return vec;
        }
        q.push(root);
        int f = 1;
        while(!q.empty())
        {
            int size= q.size();
            vector<int> v;
            
            for(int i =0; i <size;i++)
            {
                TreeNode* node =q.front();
                v.push_back(node->val);
                
                q.pop();
                if(node->left!=NULL) 
                {
                    q.push(node->left);
                }
                if(node->right!=NULL) 
                {
                    q.push(node->right);
                }
            }
            
            if(f==1)
            {
                vec.push_back(v);
                f=-1;
            }
            else
            {
                reverse(v.begin(), v.end());
                vec.push_back(v);
                f=1;
            }
            
        }
        
        return vec;
    }
};