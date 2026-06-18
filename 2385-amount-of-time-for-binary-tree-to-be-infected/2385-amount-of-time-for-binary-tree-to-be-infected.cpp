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
    int findMaxDistance(map<TreeNode*,TreeNode*>&mpp,TreeNode* target)
    {
        queue<TreeNode*>q;
        q.push(target);
        map<TreeNode*,int> vis;
        vis[target]=1;
        int maxi=0;
        while(!q.empty())
        {
            int sz=q.size();
            int fl=0; // this flag is used to see if we are actually buring something, cause there might be a time where we are on the leaf node and
            // the leaf has nothing to burn, so we cant really pudae maxi
            for(int i =0;i<sz;i++)
            {
                auto node= q.front();
                q.pop();
                if(node->left && !vis[node->left])
                {
                    fl=1;
                    vis[node->left]=1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right])
                {
                    fl=1;
                    vis[node->right]=1;
                    q.push(node->right);
                }
                if(mpp[node]&& !vis[mpp[node]])
                {
                    fl=1;
                    vis[mpp[node]]=1;
                    q.push(mpp[node]);
                }
            }
            if(fl)maxi++;

        }
        return maxi;
    }
    TreeNode* bfsToMapParent(TreeNode* root, map<TreeNode*,TreeNode*> &mpp , int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res=NULL;
        while(!q.empty())
        {
            TreeNode* node=q.front();
            if(node->val==start) {res=node;}
            q.pop();
            if(node->left!=NULL)
            {
                mpp[node->left]=node;
                q.push(node->left);
            }
            if(node->right!=NULL)
            {
                mpp[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }

    int amountOfTime(TreeNode* root, int start) {
        //  So the first thing we need to do that is figure out the node which is infected, meaning we are only given the value in the "start"
        // Also we need to map the parents out
        map<TreeNode*,TreeNode*> mpp; // through this we will know if a node has a parent or not.
        TreeNode* target= bfsToMapParent(root,mpp,start);
        int maxi= findMaxDistance(mpp,target);
        return maxi;
    }
};