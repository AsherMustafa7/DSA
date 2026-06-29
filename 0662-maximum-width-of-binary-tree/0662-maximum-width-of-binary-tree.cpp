class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }

        int ans = 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while(!q.empty())
        {
            int size = q.size();

            unsigned long long mmin = q.front().second;
            unsigned long long first, last;

            for(int i = 0; i < size; i++)
            {
                unsigned long long cur_id = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) first = cur_id;
                if(i == size - 1) last = cur_id;

                if(node->left != NULL)
                {
                    q.push({node->left, 2 * cur_id + 1});
                }

                if(node->right != NULL)
                {
                    q.push({node->right, 2 * cur_id + 2});
                }
            }

            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
    }
};