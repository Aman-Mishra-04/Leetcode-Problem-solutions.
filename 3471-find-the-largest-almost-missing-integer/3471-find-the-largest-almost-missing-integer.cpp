class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> count(51, 0);

        // Har subarray of size k
        for (int i = 0; i <= n - k; i++) {
            set<int> uniqueElements;

            for (int j = i; j < i + k; j++) {
                uniqueElements.insert(nums[j]);
            }

            // Ye elements is window me present hain
            for (int x : uniqueElements) {
                count[x]++;
            }
        }

        int ans = -1;

        // Largest element whose count is exactly 1
        for (int x = 0; x <= 50; x++) {
            if (count[x] == 1) {
                ans = x;
            }
        }

        return ans;
    }
};