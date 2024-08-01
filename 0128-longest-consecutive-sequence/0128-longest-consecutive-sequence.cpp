class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        // Sort the array to bring consecutive numbers next to each other
        sort(nums.begin(), nums.end());

        // Initialize variables
        int longest = 1;       // Stores the length of the longest consecutive sequence
        int currCount = 0;     // Stores the length of the current consecutive sequence
        int lastSmaller = INT_MIN; // Tracks the last number in the consecutive sequence

        // Iterate through the sorted array
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == lastSmaller + 1){ 
                // If the current number is consecutive to the last number
                currCount++;
                lastSmaller = nums[i]; // Update the last number in the sequence
            } 
            else if(nums[i] != lastSmaller){
                // If the current number is not part of the current sequence
                currCount = 1; // Start a new sequence
                lastSmaller = nums[i]; // Update last number to current number
            }
            // Update the longest sequence length if current is greater
            longest = max(currCount, longest);
        }

        return longest;
    }       
};
