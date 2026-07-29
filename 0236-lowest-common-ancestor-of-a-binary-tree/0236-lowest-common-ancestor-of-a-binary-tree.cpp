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
    void findpath(TreeNode* root, TreeNode* target,
                  vector<TreeNode*>& arr, vector<TreeNode*>& temp) {

        if (root == nullptr)
            return;

        temp.push_back(root);

        if (root == target) {
            arr = temp;
            temp.pop_back();
            return;
        }

        findpath(root->left, target, arr, temp);
        findpath(root->right, target, arr, temp);

        temp.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> ppath, qpath;
        vector<TreeNode*> ptemp, qtemp;

        findpath(root, p, ppath, ptemp);
        findpath(root, q, qpath, qtemp);

        TreeNode* ans = nullptr;

        for (int i = 0; i < min(ppath.size(), qpath.size()); i++) {
            if (ppath[i] == qpath[i])
                ans = ppath[i];
            else
                break;
        }

        return ans;
    }
};