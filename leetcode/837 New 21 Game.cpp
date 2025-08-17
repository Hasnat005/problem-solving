#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + 1, 0), pre;
        dp[0] = 1;
        pre = dp;
        for(int i = 1; i <= n; i++) {
            double ans = 0;
            // for(int j = 1; j <= maxPts; j++) {
            //     if(i - j >= 0 and i - j < k) 
            //         ans += dp[i - j] / maxPts;
            // }
            
            if(i <= k) {
                int r = i - 1, l = max(0, i - maxPts);
                ans += pre[r] - (l == 0 ? 0 : pre[l - 1]);
            } else {
                int r = k - 1, l = max(0, i - maxPts);
                if(l <= r) ans += pre[r] - (l == 0 ? 0 : pre[l - 1]);
            }
            dp[i] = ans / maxPts;
            pre[i] = pre[i - 1] + dp[i];
        }
        double ans = 0;
        for(int i = k; i <= n; i++) {
            ans += dp[i];
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, maxPts;
    cin >> n >> k >> maxPts;
    Solution sol;
    cout << fixed << setprecision(6) << sol.new21Game(n, k, maxPts) << '\n';
    return 0;
}