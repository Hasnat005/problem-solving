//problem link : https://https://codeforces.com/contest/1242/problem/B   

// learning : inverse graph traversal to find connected components in complement graph
// inverse graph meaning : if there is no edge between two nodes in original graph then there is an edge between them in inverse graph
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5 + 10; 

set<int> v[N];
vector<int> vis(N, 0);
int n;
set<int> s;

void dfs(int node) {
    vis[node] = 1;
    vector<int> temp;
    s.erase(node);
    for(auto i : s) {
        if(v[node].find(i) == v[node].end() and s.find(i) != s.end()) {
            temp.push_back(i);
        }
    }

    for(auto x : temp) s.erase(x);

    for(auto x : temp) {
        dfs(x);
    }
}

void solve() {
    int m; cin >> n >> m;
    while(m--) {
        int x, y; cin >> x >> y;
        v[x].insert(y);
        v[y].insert(x);
    }
    for(int i = 1; i <= n; i++) {
        s.insert(i);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt - 1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    // cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        solve();
    }
}