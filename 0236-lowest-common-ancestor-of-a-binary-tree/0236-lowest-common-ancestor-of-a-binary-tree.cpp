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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*>v1;
        vector<TreeNode*>v2;
        int flag=0;
        findlca(root,p,v1,flag);
        flag=0;
        findlca(root,q,v2,flag);
        int r1=v1.size()-1;
        int r2=v2.size()-1;
        for(auto it:v1)
        {
            cout<< it->val<<" ";
        }
        cout<< endl;
        for(auto it:v2)
        {
            cout<< it->val <<" ";
        }
        cout<<endl;
        while(r1>=0 && r2>=0)
        {
            if(v1[r1]==v2[r2])
            {
                cout<<"r1"<<r1<<endl;
                cout<<"r2"<<r2<<endl;
                r1--;
                r2--;
            }
            else
            {
                if(r1>0)
                return v1[r1+1];
                else
                return v2[r2+1];
            }
        }
        
        
        if(r1>=0)
        {
            cout<<"r1 "<<r1<<endl;
            return v1[r1+1];
        }
        
        if(r2>=0)
        {
            cout<<"r2 "<<r2<<endl;
            return v2[r2+1];
        }
        
        return NULL;
    }
    void findlca(TreeNode* root, TreeNode* f,vector<TreeNode*>&v,int &flag)
    {
        if(root==NULL)
        {
            return;
        }
        if(root==f)
        {
            v.push_back(root);
            flag=1;
            return;
        }
        if(flag==0)
        findlca(root->left,f,v,flag);
        if(flag==0)
        findlca(root->right,f,v,flag);
        if(flag==1)
        v.push_back(root);
    }
};