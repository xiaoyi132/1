class Solution {
public:
    string replaceSpaces(string S, int length) {
        string ret;
        for (size_t i = 0; i < length; i++)
        {
            if (S[i] != ' ')
            {
                ret += S[i];
            }
            else
            {
                ret += "%20";
            }
        }
        return ret;
    }
};