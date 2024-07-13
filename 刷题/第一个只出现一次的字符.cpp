#include<iostream>
using namespace std;
#include<string>
#include<vector>
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        vector<int> hash_table;
        hash_table.resize(256, 0);
        //ʹ��map���ƻ�ԭ���ַ�����˳��,���ù�ϣӳ��
        for (auto& ch : str)
        {
            hash_table[ch]++;
        }
        for (auto& ch : str)
        {
            if (hash_table[ch] == 1)
            {
                return str.find(ch);
            }
        }
        return -1;
    }
};