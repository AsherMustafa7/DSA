/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Serialize
    string serialize(TreeNode* root)
    {
        if(root == NULL)
            return "";

        string s;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if(node)
            {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                s += "N,";
            }
        }

        s.pop_back();          // remove last comma
        return s;
    }

    // Deserialize
    TreeNode* deserialize(string data)
    {
        if(data.empty())
            return NULL;

        vector<string> str;
        string temp = "";

        for(char c : data)
        {
            if(c == ',')
            {
                str.push_back(temp);
                temp = "";
            }
            else
            {
                temp += c;
            }
        }
        str.push_back(temp);

        TreeNode* root = new TreeNode(stoi(str[0]));

        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while(!q.empty() && i < str.size())
        {
            TreeNode* node = q.front();
            q.pop();

            // left child
            if(str[i] != "N")
            {
                node->left = new TreeNode(stoi(str[i]));
                q.push(node->left);
            }
            i++;

            // right child
            if(i < str.size() && str[i] != "N")
            {
                node->right = new TreeNode(stoi(str[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};