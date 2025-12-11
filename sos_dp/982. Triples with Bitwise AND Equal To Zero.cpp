#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    // -----------------------------------------------------------
    // 3. SUPERSET SUM (Forward)
    // Transforms array so A[mask] = Sum(A[super]) where mask ⊆ super
    // -----------------------------------------------------------
    void super_forward(long long dp[], int N) {
        for (int i = 0; i < N; ++i) {
            for (int mask = (1 << N) - 1; mask >= 0; --mask) {
                if (mask & (1 << i)) {
                    dp[mask ^ (1 << i)] += dp[mask];
                }
            }
        }
    }

    // -----------------------------------------------------------
    // 4. SUPERSET SUM (Backward / Inverse)
    // Reverts the Superset transformation
    // -----------------------------------------------------------
    void super_backward(long long dp[], int N) {
        for (int i = 0; i < N; ++i) {
            for (int mask = 0; mask < (1 << N); ++mask) {
                if (mask & (1 << i)) {
                    dp[mask ^ (1 << i)] -= dp[mask];
                }
            }
        }
    }
    long long dp[(1 << 16)];
    int countTriplets(vector<int>& a) {
        for(auto x : a) dp[x]++;
        super_forward(dp, 16);
        for(int i = 0; i < (1 << 16); i++) {
            dp[i] = dp[i] * dp[i] * dp[i];
        }
        super_backward(dp, 16);
        return dp[0];
    }
};

int main() {
    Solution sol;
    vector<int> a = {2,1,3};
    cout << sol.countTriplets(a) << endl; // Output: 12
    return 0;
}