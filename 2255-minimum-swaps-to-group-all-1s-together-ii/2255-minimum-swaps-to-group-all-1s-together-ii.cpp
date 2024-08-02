class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(auto num : nums){
            if(num == 1){
                count++;
            }
        }
        
        if(count == 0 || count == n) return 0;

        // take 3 size of window

        int count_zeroes = 0;
        for(int i = 0; i < count; i++){
            if(nums[i] == 0){
                count_zeroes++;
            }
        }

        // slide the window across the array..
        int min_swap = count_zeroes;

        for(int i = 1; i < n; i++){
            // remove the element that goes out of the window
            if(nums[i - 1] == 0){
                count_zeroes--;
            }

            //add the element that comes in the window
            if(nums[(i + count - 1) % n] == 0){     // (i + count - 1) % n to handle the circular nature of the array.
                count_zeroes++;
            }

            min_swap = min(min_swap, count_zeroes);
        }
        return min_swap;
    }
};