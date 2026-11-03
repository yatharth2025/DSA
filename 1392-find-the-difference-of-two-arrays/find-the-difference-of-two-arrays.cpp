class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> a(nums1.begin(), nums1.end());
        set<int> b(nums2.begin(), nums2.end());

        vector<vector<int>> ans(2);

        for (int x : a)
            if (!b.count(x)) ans[0].push_back(x);

        for (int x : b)
            if (!a.count(x)) ans[1].push_back(x);

        return ans;
    }
};