#include <iostream>
using namespace std;
#include<string>
int main() {
    int n;
    while (cin >> n) {
        int num = 0;
        for (size_t i = 1; i <= n; i++)
        {
            string str_pow;
            string str_n = to_string(i);
            str_pow = to_string(i * i);
            if (str_pow.substr(str_pow.size() - str_n.size(), str_n.size()) == str_n)
            {
                ++num;
            }
        }
        cout << num << endl;
    }
}