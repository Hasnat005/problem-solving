//problem link : https://codeforces.com/contest/1036/problem/C

#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n;
long long dp[20][2][4];
int f(int i, int flag, int nz) {
    if(i == n) return 1;
    int &ans = dp[i][flag][nz];
    if(~ans) return ans;
    ans = 0;
    if(flag == 0) {
        int x = s[i] - '0';
        for(int j = 0; j <= x; j++) {
            if(j == x) {
                int non_zero = nz;
                if(j != 0) non_zero++;
                if(non_zero <= 3) ans += f(i + 1, 0, non_zero);
            } else {
                int non_zero = nz;
                if(j != 0) non_zero++;
                if(non_zero <= 3) ans += f(i + 1, 1, non_zero);
            }
        }
    } else {
        for(int j = 0; j <= 9; j++) {
            int non_zero = nz;
            if(j != 0) non_zero++;
            if(non_zero <= 3) ans += f(i + 1, 1, non_zero);
        }
    }
    return ans;
}

void solve() {
    long long l, r; cin >> l >> r;
    memset(dp, -1, sizeof(dp));
    s = to_string(r);
    n = s.size();
    int R = f(0, 0, 0);
    // cout << R << "\n";
    l--;
    memset(dp, -1, sizeof(dp));
    s = to_string(l);
    n = s.size();
    int L = f(0, 0, 0);
    cout << R - L << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}