#include <iostream>
using namespace std;
int main() {
    int n;
    string str;
    cin >> n;
    while (n--) {
        string ret;
        cin >> str;
        if (str.size() >= 10)
        {
            ret += str[0];
            ret += to_string(str.size() - 2);
            ret += str[str.size() - 1];
        }
        else
            ret += str;
        cout << ret << endl;
    }
}