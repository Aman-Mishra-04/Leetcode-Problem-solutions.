class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long sum = 0;
        int l = 0;
        int ans = 1;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            // Operations needed to make every element
            // in [l...r] equal to nums[r]
            long long operations = 
                1LL * nums[r] * (r - l + 1) - sum;

            // Window is not possible
            while (operations > k) {
                sum -= nums[l];
                l++;

                operations =
                    1LL * nums[r] * (r - l + 1) - sum;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};