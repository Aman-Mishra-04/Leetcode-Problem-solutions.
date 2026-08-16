class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        // No stones with remainder 1 or 2:
        // Alice can never make the sum divisible by 3,
        // so eventually all stones are removed and Bob wins.
        if (cnt[1] == 0 && cnt[2] == 0)
            return false;

        // If there are no remainder-0 stones,
        // Alice wins exactly when both types exist
        // and their counts are not equal in the losing pattern.
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        return abs(cnt[1] - cnt[2]) > 2;
    }
};