#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        for(auto vec : queries) {
            int l = vec[0], r = vec[1], k = vec[2], v = vec[3];
            for(int i = l; i <= r; i += k) {
                nums[i] = 1ll * nums[i] * v % mod;
            }
        }
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);     
    vector<int> nums;
    int n, m;
    cin >> n >> m;
    nums.resize(n); 
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> queries(m, vector<int>(4));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> queries[i][j];
        }
    }   
    Solution sol;
    cout << sol.xorAfterQueries(nums, queries) << '\n';
    return 0;
}