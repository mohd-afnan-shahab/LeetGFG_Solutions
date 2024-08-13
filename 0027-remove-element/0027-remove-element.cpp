class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == val) {
                // Shift elements to the left
                for (int j = i; j < n - 1; j++) {
                    nums[j] = nums[j + 1];
                }
                n--; // Reduce size of array
                i--; // Decrement index to check the current position again
            }
        }
        return n;
    }
};
