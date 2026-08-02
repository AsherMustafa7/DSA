/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode*,TreeNode*>mp;
        queue<TreeNode*>q;
        vector<int>v;
        store(root,mp);
        q.push(target);
        
        int diff=0;
        unordered_map<TreeNode*,int>vis;
        vis[target]=1;
        while(!q.empty())
        {
            int n =q.size();
            if(diff==k)
                {
                    break;
                }
            while(n--)
            {
                
                TreeNode* node=q.front();
                q.pop();
                
                if(mp.find(node)!=mp.end() && vis.find(mp[node])==vis.end())
                {
                    q.push(mp[node]);
                    vis[node]=1;
                }
                if(node->left!=NULL && vis.find(node->left)==vis.end())
                {
                    q.push(node->left);
                    vis[node]=1;
                }
                if(node->right!=NULL && vis.find(node->right)==vis.end())
                {
                    q.push(node->right);
                    vis[node]=1;
                }
            }
            diff++;
            
        }
        while(!q.empty())
        {
            TreeNode* node=q.front();
            v.push_back(node->val);
            q.pop();
        }
        return v;
    }
    void store(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp)
    {
        if(root==NULL){return;}
        if(root->left)
        {
            mp[root->left]=root;
        }
        if(root->right)
        {
            mp[root->right]=root;
        }
        store(root->left,mp);
        store(root->right,mp);
    }
};