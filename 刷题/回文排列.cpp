class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, size_t> mp;
        for (const auto& ch : s)
        {
            mp[ch]++;
        }
        size_t count = 0;
        for (const auto& pa : mp)
        {
            if (pa.second % 2 == 1)
                count++;
            if (count > 1)
                return false;
        }
        return true;
    }
};