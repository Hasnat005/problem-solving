#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), cmp);
        long long ans = 0, last = -1e15;
        for(auto x : v) {
            int st = x[0], en = x[1];
            if(st <= last and last <= en) {

            } else {
                last = en;
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v = {{10,16},{2,8},{1,6},{7,12}};
    cout << sol.findMinArrowShots(v) << '\n';
    return 0;
}