class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt = 0, ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (string("aeiou").find(s[i]) != string::npos)
                cnt++;

            if (i >= k && string("aeiou").find(s[i-k]) != string::npos)
                cnt--;

            ans = max(ans, cnt);
        }

        return ans;
    }
};