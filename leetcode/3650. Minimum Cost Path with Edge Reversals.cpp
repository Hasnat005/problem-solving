#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        const int x = n;
        vector<pair<int, int>> g[x];
        for(auto x : edges) {
            int u = x[0], v = x[1], w = x[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w * 2});
        }
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int u = it.first;
            int w = it.second;
            for(auto V : g[u]) {
                int v = V.first;
                int w = V.second;
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({v, dist[v]});
                } 
            }
        }
        return dist[n - 1] == 1e9 ? -1 : dist[n - 1];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int m = n - 1;

    vector<vector<int>> edges;
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    Solution sol;
    cout << sol.minCost(n, edges) << '\n';
    return 0;
}
