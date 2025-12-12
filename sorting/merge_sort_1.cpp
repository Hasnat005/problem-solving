// https://leetcode.com/problems/count-of-range-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Use long long to prevent integer overflow
    vector<long long> pre;
    int low, high;

    int f(int l, int r) {
        if (l >= r) return 0; // Base case: need at least 2 indices to form a range

        int mid = (l + r) / 2;

        // 1. Divide
        int ans = f(l, mid) + f(mid + 1, r);

        // 2. Count Valid Ranges
        // We need to find pairs (i, j) such that: low <= pre[j] - pre[i] <= high
        // For every i in left half, we find the range [start, end) in right half.
        int start = mid + 1, end = mid + 1;
        for (int i = l; i <= mid; i++) {
            // Find the first index in right half where sum is >= low
            while (start <= r && pre[start] - pre[i] < low) {
                start++;
            }
            // Find the first index in right half where sum is > high
            while (end <= r && pre[end] - pre[i] <= high) {
                end++;
            }
            ans += (end - start);
        }

        // 3. Merge (Standard Merge Sort)
        vector<long long> sorted;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (pre[i] < pre[j]) {
                sorted.push_back(pre[i++]);
            } else {
                sorted.push_back(pre[j++]);
            }
        }
        while (i <= mid) sorted.push_back(pre[i++]);
        while (j <= r) sorted.push_back(pre[j++]);

        // Copy back to original array
        for (int k = 0; k < sorted.size(); k++) {
            pre[l + k] = sorted[k];
        }

        return ans;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        // Resize to n+1 and initialize with 0
        pre.resize(n + 1, 0); 
        
        // Calculate prefix sums: pre[i] = sum(nums[0]...nums[i-1])
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        
        low = lower;
        high = upper;
        
        // Call recursive function on the full range of the prefix array
        return f(0, n);
    }
};


int main() {
    Solution sol;
    vector<int> nums = {-2, 5, -1};
    int lower = -2, upper = 2;
    int result = sol.countRangeSum(nums, lower, upper);
    cout << "Count of range sums: " << result << endl; // Expected output: 3
    return 0;
}