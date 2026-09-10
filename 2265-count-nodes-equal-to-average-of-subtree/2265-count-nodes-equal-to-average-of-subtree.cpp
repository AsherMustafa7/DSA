
class Solution {
public:

    // Find sum and count of a subtree
    void avg(TreeNode* Node, int &count, int &sum)
    {
        if(Node == NULL)
            return;

        count++;
        sum += Node->val;

        avg(Node->left, count, sum);
        avg(Node->right, count, sum);
    }


    // Check whether the current node's value
    // is equal to the average of its subtree
    void search(TreeNode* Node, int &ans)
    {
        if(Node == NULL)
            return;

        int count = 0;
        int sum = 0;

        // Find sum and count of THIS node's subtree
        avg(Node, count, sum);

        int average = sum / count;

        // Check current node
        if(Node->val == average)
            ans++;

        // Now do the same for its children
        search(Node->left, ans);
        search(Node->right, ans);
    }


    int averageOfSubtree(TreeNode* root)
    {
        int ans = 0;

        // Start searching from root
        search(root, ans);

        return ans;
    }
};
