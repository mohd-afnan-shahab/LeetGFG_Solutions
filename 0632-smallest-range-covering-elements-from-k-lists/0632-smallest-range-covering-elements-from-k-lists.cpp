class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();  // number of lists
        vector<int> indices(k, 0);  // tracks the current index for each list
        vector<int> resultRange = {-1000000, 1000000};  // stores the final range

        while (true) {
            int minEl = INT_MAX;
            int maxEl = INT_MIN;
            int minListIdx = 0;

            // Find the minimum and maximum elements across the current elements of each list
            for (int i = 0; i < k; ++i) {
                int listIdx = i;
                int eleIdx = indices[i];
                int element = nums[listIdx][eleIdx];

                if (element < minEl) {
                    minEl = element;
                    minListIdx = listIdx;
                }

                maxEl = max(maxEl, element);
            }

            // Update the result range if a smaller range is found
            if (maxEl - minEl < resultRange[1] - resultRange[0]) {
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }

            // Move to the next element in the list containing the minimum element
            int nextIndex = indices[minListIdx] + 1;
            if (nextIndex >= nums[minListIdx].size()) {
                break;  // Stop if we've processed all elements in one of the lists
            }
            indices[minListIdx] = nextIndex;
        }

        return resultRange;
    }
};
