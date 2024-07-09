#include <iostream>
using namespace std;
#include<math.h>
int main() {
    int n;
    while (cin >> n) {
        size_t count = 0;
        for (size_t i = 2; i < n; ++i)
        {
            bool flag = true;
            size_t num = 2;
            while (num <= sqrt(i))
            {
                if (i % num == 0)
                {
                    flag = false;
                    break;
                }
                else
                {
                    num++;
                }
            }
            if (flag)
                count++;
        }
        cout << count;
    }
}