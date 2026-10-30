class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int n = matrix[0].size(), ans = 0;
        vector<int> h(n + 1, 0);

        for(auto &row : matrix) {
            for(int j = 0; j < n; j++)
                h[j] = row[j] == '1' ? h[j] + 1 : 0;

            stack<int> st;
            for(int j = 0; j <= n; j++) {
                while(!st.empty() && h[st.top()] > h[j]) {
                    int height = h[st.top()];
                    st.pop();
                    int width = st.empty() ? j : j - st.top() - 1;
                    ans = max(ans, height * width);
                }
                st.push(j);
            }
        }
        return ans;
    }
};