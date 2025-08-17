#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:

    int f(int a, int b) {
        return (a + b - 1) / b;
    }
    long long perfectPairs(vector<int>& nums) {
        vector<int> a = nums;
        int n = a.size();
        long long ans = 0;
        o_set<int> se;
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
                if(a[i] > 0) {
                    int l = -a[i] * 2, r = -f(a[i], 2);
                    int x = se.order_of_key(r + 1) - se.order_of_key(l);
                    l = f(a[i], 2), r = a[i] * 2;
                    int y = se.order_of_key(r + 1) - se.order_of_key(l);
                    ans += x + y;
                    
                } else if(a[i] < 0) {
                    int l = a[i] * 2, r = -f(abs(a[i]), 2);
                    int x = se.order_of_key(r + 1) - se.order_of_key(l);
                    // cout << l << ' ' << r << '\n';
                    l = abs(r), r = abs(a[i] * 2);
                    int y = se.order_of_key(r + 1) - se.order_of_key(l);
                    // cout << l << ' ' << r << '\n';
                    ans += x + y;
                } else {
                    ans += mp[a[i]];
                    mp[a[i]]++;
                }
                se.insert(a[i]);
            
        }
        return ans;
    }
};