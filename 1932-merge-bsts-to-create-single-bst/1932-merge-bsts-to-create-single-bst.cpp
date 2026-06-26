/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    unordered_map<int, TreeNode*> rootMap;
    unordered_set<int> leaves;

    TreeNode* canMerge(vector<TreeNode*>& trees) {

        // store every root
        for (auto t : trees)
            rootMap[t->val] = t;

        // store every leaf value
        for (auto t : trees) {
            if (t->left) leaves.insert(t->left->val);
            if (t->right) leaves.insert(t->right->val);
        }

        // find the only root that never appears as a leaf
        TreeNode* root = NULL;

        for (auto t : trees) {
            if (!leaves.count(t->val)) {
                root = t;
                break;
            }
        }

        if (root == NULL)
            return NULL;

        rootMap.erase(root->val);

        if (!dfs(root, LLONG_MIN, LLONG_MAX))
            return NULL;

        if (!rootMap.empty())
            return NULL;

        return root;
    }

    bool dfs(TreeNode* node, long long mn, long long mx) {

        if (!node)
            return true;

        if (node->val <= mn || node->val >= mx)
            return false;

        // If this node is a leaf and another tree starts here,
        // merge that tree.
        if (node->left == NULL && node->right == NULL) {

            auto it = rootMap.find(node->val);

            if (it != rootMap.end()) {

                TreeNode* merge = it->second;

                node->left = merge->left;
                node->right = merge->right;

                rootMap.erase(it);
            }
        }

        return dfs(node->left, mn, node->val) &&
               dfs(node->right, node->val, mx);
    }
};