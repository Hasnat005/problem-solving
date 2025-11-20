#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if (n == 0 || k == 0) return 0;

        bool all_equal = true;
        for (int i = 1; i < n && all_equal; ++i) {
            if (nums[i] != nums[0]) all_equal = false;
        }
        if (all_equal) return 0;

        vector<long long> a(2 * n);
        for (int i = 0; i < 2 * n; ++i) a[i] = nums[i % n];

        const long long NEG = LLONG_MIN / 4;
        int maxP = min(2 * k, n);

        vector<long long> dp0(maxP + 1, NEG), dp1(maxP + 1, NEG), dp2(maxP + 1, NEG);
        vector<long long> best0(maxP + 1, NEG);

        long long ans = 0;

        for (int start = 0; start < n; ++start) {
            fill(dp0.begin(), dp0.end(), NEG);
            fill(dp1.begin(), dp1.end(), NEG);
            fill(dp2.begin(), dp2.end(), NEG);
            dp0[0] = 0;

            int limit = 0;
            for (int off = 0; off < n; ++off) {
                long long v = a[start + off];
                limit = min(maxP, off + 1);
                dp0[limit] = dp1[limit] = dp2[limit] = NEG;

                for (int p = limit - 1; p >= 0; --p) {
                    long long val0 = dp0[p];
                    if (val0 != NEG) {
                        long long cand = val0 + v;
                        if (cand > dp1[p + 1]) dp1[p + 1] = cand;
                    }

                    long long val1 = dp1[p];
                    if (val1 != NEG) {
                        long long candPlus = val1 + v;
                        if (p + 1 <= maxP && candPlus > dp2[p + 1]) dp2[p + 1] = candPlus;
                        long long candMinus = val1 - v;
                        if (p + 1 <= maxP && candMinus > dp0[p + 1]) dp0[p + 1] = candMinus;
                    }

                    long long val2 = dp2[p];
                    if (val2 != NEG) {
                        long long cand = val2 - v;
                        if (cand > dp1[p + 1]) dp1[p + 1] = cand;
                    }
                }
            }

            long long best = 0;
            for (int p = 0; p <= maxP; ++p) {
                best = max(best, dp0[p]);
            }
            ans = max(ans, best);
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    cout << Solution().maximumScore(nums, k) << "\n";
    return 0;
}