class Solution {
public:
    void dfs(TreeNode* root, vector<int>& v) {
        if (!root) return;

        if (!root->left && !root->right) {
            v.push_back(root->val);
            return;
        }

        dfs(root->left, v);
        dfs(root->right, v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;

        dfs(root1, a);
        dfs(root2, b);

        return a == b;
    }
};