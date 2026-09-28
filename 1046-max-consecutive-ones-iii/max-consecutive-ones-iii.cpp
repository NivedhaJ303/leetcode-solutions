class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int zeros = 0;
        int maxLen = 0;

        while (r < nums.size()) {

            if (nums[r] == 0)
                zeros++;

            if (zeros > k) {
                if (nums[l] == 0)
                    zeros--;

                l++;
            }

            if (zeros <= k) {
                maxLen = max(maxLen, r - l + 1);
            }

            r++;
        }

        return maxLen;
    }
};