class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt = count(nums.begin(), nums.end(), 1);

        if(cnt == 0 || cnt == n) return 0;

        // take 3 size of window
        int count_zeroes = 0;
        for(int i = 0; i < cnt; i++){
            if(nums[i] == 0){
                count_zeroes++;
            }
        }

        int min_swap = count_zeroes;
        for(int i = 1; i < n; i++){
            // remove the element that goes out of the window
            if(nums[i - 1] == 0){
                count_zeroes--;
            }

            //add the element that comes in the window
            if(nums[(i + cnt - 1) % n] == 0){     // (i + count - 1) % n to handle the circular nature of the array.
                count_zeroes++;
            }

            min_swap = min(min_swap, count_zeroes);
        }
        return min_swap;
    }
};


