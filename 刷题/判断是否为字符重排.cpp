class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        // map<char,size_t> mp_s1;
        // map<char,size_t> mp_s2;
        // for(const auto& ch : s1)
        // {
        //     mp_s1[ch]++;
        // }

        // for(const auto& ch : s2)
        // {
        //     mp_s2[ch]++;
        // }
        // std::map<char,size_t>::iterator it = mp_s2.begin();
        // for(const auto& pa:mp_s1)
        // {
        //     if(pa.first == it->first && pa.second == it->second)
        //         it++;
        //     else
        //         return false;
        // }
        // if(it == mp_s2.end())
        //     return true;
        // else
        //     return false;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};