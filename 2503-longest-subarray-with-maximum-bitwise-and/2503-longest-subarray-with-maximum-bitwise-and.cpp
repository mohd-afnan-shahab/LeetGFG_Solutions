class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = 0;
        int result = 0;
        int maxLength = 0;

        for (auto num : nums) {
            if (num > maxValue) {
                maxValue = num;
                result = 0;  // Reset result when new max value is found
                maxLength = 0;  // Reset the current maxLength
            }

            if (maxValue == num) {
                maxLength++;
            } else {
                maxLength = 0;
            }

            result = max(result, maxLength); 
        }

        return result; 
    }
};
