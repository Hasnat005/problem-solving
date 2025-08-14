#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;
const int N = 1e5; 

void solve() {
    int n; cin >> n;
    if(n % 2 == 0) {
        int x;
        if(n == 2) x = 2;
        else x = 3;
        cout << -1 << ' ' << x << ' ';
        for(int i = 3; i <= n; i++) {
            if(i % 2) cout << -1 << ' ';
            else {
                if(i == n) cout << 2 << ' ';
                else cout << 3 << ' ';
            }
        }
        cout << '\n';
    } else {
        cout << -1 << ' ' << 3 << ' ' << -1 << ' ';
        for(int i = 4; i <= n; i++) {
            if(i % 2) cout << -1 << ' ';
            else cout << 3 << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        solve();
    }
}