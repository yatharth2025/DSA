class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        set<int> s;

        for (int x : arr)
            mp[x]++;

        for (auto [x, cnt] : mp)
            s.insert(cnt);

        return s.size() == mp.size();
    }
};