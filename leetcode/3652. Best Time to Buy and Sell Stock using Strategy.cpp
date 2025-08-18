#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long n = prices.size(), sum = 0;
        vector<long long> pre(n, 0), psum(n, 0);
         for(int i = 0; i < n; i++) {
             if(i) pre[i] = pre[i - 1] + prices[i];
             else pre[i] = prices[i];
             sum += strategy[i] * prices[i];
             psum[i] = sum;
         }   
        long long ans = sum;
        for(int i = 0; i < n; i++) {
            int l = i, r = i + k - 1;
            if(r >= n) break;
            long long temp = sum - (psum[r] - (l == 0 ? 0 : psum[l - 1]));
            l = i + k / 2;
            temp += (pre[r] - (l == 0 ? 0 : pre[l - 1]));
            ans = max(ans, temp);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> prices(n), strategy(n);
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> strategy[i];
    }
    Solution sol;
    cout << sol.maxProfit(prices, strategy, k) << '\n';
    return 0;
}