//problem link : https://leetcode.com/problems/number-of-digit-one/description/?source=submission-ac

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    string s;
    int f(int idx, int flag, int cnt, vector<vector<vector<int>>> &dp) {
        if(idx == 0) return cnt;
        int &ans = dp[idx][flag][cnt];
        if(~ans) return ans;
        ans = 0;
        if(flag == 0) {
            int x = s[idx - 1] - '0';
            for(int i = 0; i <= x; i++) {
                if(i == x) {
                    int p = 0;
                    if(i == 1) p = 1;
                    ans += f(idx - 1, 0, cnt + p, dp);
                } else {
                    int p = 0;
                    if(i == 1) p = 1;
                    ans += f(idx - 1, 1, cnt + p, dp);
                }
            }
        } else {
            for(int i = 0; i <= 9; i++) {
                    int p = 0;
                    if(i == 1) p = 1;
                ans += f(idx - 1, 1, cnt + p, dp);
            }
        }
        return ans;
    }
    int countDigitOne(int n) {
        s = to_string(n);
        int len = s.size();
        vector<vector<vector<int>>> dp(len + 2, vector<vector<int>> (2, vector<int> (12, -1)));
        reverse(s.begin(), s.end());
        return f(len, 0, 0, dp);
    }
};


int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.countDigitOne(n) << endl;
    return 0;
}