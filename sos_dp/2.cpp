// https://codeforces.com/contest/449/problem/D

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
long long dp[1 << 20];

int power(int a, int n) {
   if (n == 0) return 1;
   if (n == 1) return a % mod;
   int x = power(a, n / 2);
   if (n % 2 == 0) {
     return 1LL * x * x % mod;
   }
   else {
     return 1LL * x * x % mod * a % mod;
   }
} 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
      int x; cin >> x;
      dp[x]++;
    }
    super_forward(dp, 20);
    for(int i = 0; i < (1 << 20); i++) {
      dp[i] = (power(2, dp[i]) - 1 + mod) % mod;
    }
    super_backward(dp, 20);
    cout << dp[0] << '\n';
}