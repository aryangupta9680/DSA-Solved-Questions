class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long p = *max_element(nums.begin(), nums.end());
        long long q = *min_element(nums.begin(), nums.end());
        return 1LL*k*(p - q);
    }
};