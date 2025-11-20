#include <bits/stdc++.h>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) {
    if (a[1] == b[1])
        return a[0] > b[0]; 
    return a[1] < b[1];     
}

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), cmp);
        long long ans = 0, last = -1e15, sec_last = -1e15;
        for(auto x : v) {
            int st = x[0], en = x[1];
            if(st <= sec_last and sec_last <= en) {

            } else if(st <= last and last <= en) {
                ans += 1;
                sec_last = last;
                last = en;
            } else {
                last = en;
                sec_last = en - 1;
                ans += 2;
            }
            cout << sec_last << ' ' << last << '\n';

        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v = {{1,3},{1,4},{2,5},{3,5}};
    cout << sol.intersectionSizeTwo(v) << '\n';
    return 0;
}