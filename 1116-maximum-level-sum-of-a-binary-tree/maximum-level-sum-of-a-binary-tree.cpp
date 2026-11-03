class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = 1, level = 0, mx = INT_MIN;

        while (!q.empty()) {
            int n = q.size(), sum = 0;
            level++;

            while (n--) {
                auto node = q.front();
                q.pop();

                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (sum > mx) {
                mx = sum;
                ans = level;
            }
        }

        return ans;
    }
};