#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int a, int b) {
        return (a + b - 1) / b;
    }
    int minSensors(int n, int m, int k) {
        int x = f(n, 2 * k + 1);
        int y = f(m, 2 * k + 1);
        return x * y;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    Solution sol;
    cout << sol.minSensors(n, m, k) << '\n';
    return 0;
}