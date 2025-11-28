#include<bits/stdc++.h>
using namespace std;
 
const int mod = 1e9 + 7, N = 1e5 + 7;
 
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
            }
        }
    }
}
 
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
 
long long dp1[(1 << 20)] = {0};
long long dp2[(1 << 20)] = {0};
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      int x; cin >> x;
      dp1[x]++;
      dp2[x]++;
      a[i] = x;
    }
    sos_forward(dp1, 20);
    super_forward(dp2, 20);
    for(auto x : a) {
      cout << dp1[x] << ' ' << dp2[x] << ' ' << n - dp1[((1 << 20) - 1) ^ x] << '\n';
    }
}