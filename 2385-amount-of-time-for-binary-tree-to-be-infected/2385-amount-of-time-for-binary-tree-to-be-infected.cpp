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
    void find(TreeNode* root,int start,TreeNode* &target)
    {
        if(root==NULL)
        {
            return;
        }
        if(target==nullptr)
        {
            if(root->val==start)
            {
                target=root;
            }
            find(root->left,start,target);
            find(root->right,start,target);
        }
        else
        {
            return;
        }
        
    }
    int amountOfTime(TreeNode* root, int start) 
    {
        TreeNode* target=nullptr;
        find(root,start,target);
        unordered_map<TreeNode*,TreeNode*>mp;
        queue<TreeNode*>q;
        store(root,mp);
        q.push(target);
        
        int diff=0;
        unordered_map<TreeNode*,int>vis;
        vis[target]=1;
        while(!q.empty())
        {
            int n =q.size();
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
        
        return diff-1;
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