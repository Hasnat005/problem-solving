//problem link : https://www.spoj.com/problems/GONE/

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int N = 1000; 
bitset<N> prime;
string s;
int n;
int dp[20][2][200];
int f(int i, int flag, int sum) {
    if(i == n) {
        // cout << sum << ' ' << prime[sum] << '\n';
        if(!prime[sum] and sum) return 1;
        return 0;
    }
    int &ans = dp[i][flag][sum];
    if(~ans) return ans;
    ans = 0;
    if(flag == 0) {
        int x = s[i] - '0';
        for(int j = 0; j <= x; j++) {
            if(j == x) {
                ans += f(i + 1, 0, sum + j);
            } else {
                ans += f(i + 1, 1, sum + j);
            }
        }
    } else {
        for(int j = 0; j <= 9; j++) {
            ans += f(i + 1, 1, sum + j);
        }
    }
    return ans;
}


void solve() {
    int l, r; cin >> l >> r;

    s = to_string(r);
    n = s.size();
    memset(dp, -1, sizeof(dp));
    int R = f(0, 0, 0);
    l--;
    s = to_string(l);
    n = s.size();
    memset(dp, -1, sizeof(dp));
    int L = f(0, 0, 0);
    cout << R - L << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prime[1] = true;
  for (int i = 2; i * i < N; i++) {
    if (!prime[i]) {
      for (int j = i * i; j < N; j += i) {
        prime[j] = true;
      }
    }
  }
    // for(int i = 1; i <= 10; i++) {
    //     cout << prime[i] << ' ' << i << '\n';
    // }
    int t = 1; 
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        solve();
    }
}