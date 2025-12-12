// https://leetcode.com/problems/sort-an-array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(int l, int mid, int r, vector<int> &a) {

        int i = l, j = mid + 1, k = 0;
        vector<int> sorted(r - l + 1);
        while(i <= mid and j <= r) {
            if(a[i] < a[j]) {
                sorted[k++] = a[i++];
            } else {
                sorted[k++] = a[j++];
            }
        }
        while(i <= mid) {
            sorted[k++] = a[i++];
        }
        while(j <= r) {
            sorted[k++] = a[j++];
        }
        for(int k = 0; k < (r - l + 1); k++) {
            a[l + k] = sorted[k];
        }
    }

    void merge_sort(int l, int r, vector<int> &a) {
        if(l >= r) return;
        
        int mid = (l + r) / 2;
        merge_sort(l, mid, a);
        merge_sort(mid + 1, r, a);

        merge(l, mid, r, a);
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(0, nums.size() - 1, nums);
        return nums;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {5, 2, 3, 1};
    vector<int> sorted_nums = sol.sortArray(nums);
    for (int num : sorted_nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}