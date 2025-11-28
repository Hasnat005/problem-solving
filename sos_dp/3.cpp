#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
// 20 bits is enough to hold 10^6 (since 2^20 = 1,048,576)
const int MAX_BITS = 20; 
long long dp[1 << MAX_BITS];

class Solution {
private:
    // -----------------------------------------------------------
    // 1. SUBSET SUM (Forward)
    // Transforms array so A[mask] = Sum(A[sub]) where sub ⊆ mask
    // -----------------------------------------------------------
    void sos_forward(long long dp[], int N) {
        for (int i = 0; i < N; ++i) {
            for (int mask = 0; mask < (1 << N); ++mask) {
                if (mask & (1 << i)) {
                    dp[mask] += dp[mask ^ (1 << i)];
                }
            }
        }
    }

    // -----------------------------------------------------------
    // 2. SUBSET SUM (Backward / Inverse)
    // Reverts the SOS transformation
    // -----------------------------------------------------------
    void sos_backward(long long dp[], int N) {
        for (int i = 0; i < N; ++i) {
            for (int mask = (1 << N) - 1; mask >= 0; --mask) {
                if (mask & (1 << i)) {
                    dp[mask] -= dp[mask ^ (1 << i)];
                    if (dp[mask] < 0) dp[mask] += MOD; 
                }
            }
        }
    }

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int countEffective(vector<int>& nums) {
        // 1. Reset Global Memory (Crucial for multiple test cases)
        memset(dp, 0, sizeof(dp));

        int full_or = 0;
        int max_val = 0;
        int n = nums.size();
        
        // 2. Populate Frequency and find Range
        for (int num : nums) {
            full_or |= num;
            max_val = max(max_val, num);
            dp[num]++;
        }

        // 3. Determine necessary bits dynamically
        // If max_val is small, we don't need to loop 2^20 times.
        int bits = 0;
        while ((1 << bits) <= max_val) {
            bits++;
        }
        // Safety clamp (though constraints say <= 10^6, so <= 20 bits)
        if (bits > MAX_BITS) bits = MAX_BITS;

        // 4. Run SOS DP
        sos_forward(dp, bits);

        // 5. Transform: Convert subset counts to subsequence counts
        // dp[mask] = 2^(count of items strictly inside mask)
        int limit = 1 << bits;
        for(int i = 0; i < limit; i++) {
            dp[i] = power(2, dp[i]);
        }

        sos_backward(dp,bits);

        // 6. Calculate Answer
        // dp[full_or] is now the number of subsequences where OR == full_or.
        // We want subsequences where OR < full_or.
        // Effective = Total - (Subsequences where OR == full_or)
        
        long long total_subsequences = power(2, n);
        long long effective_subsequences = (total_subsequences - dp[full_or] + MOD) % MOD;
        
        return effective_subsequences;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution sol;
    cout << sol.countEffective(a) << "\n";
    return 0;
}