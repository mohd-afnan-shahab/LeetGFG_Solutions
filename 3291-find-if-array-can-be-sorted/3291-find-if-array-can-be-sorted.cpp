class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        int setbits = __builtin_popcount(nums[0]);
        int maxi = nums[0];
        int mini = nums[0];

        int prevMax = INT_MIN;

        for(int i = 1; i < n; i++){

            if(setbits == __builtin_popcount(nums[i])){
                maxi = max(maxi, nums[i]);
                mini = min(mini, nums[i]);
            }

            else{

                if(prevMax > mini) return false;

                // other segment
                
                setbits = __builtin_popcount(nums[i]);
                prevMax = maxi;
                maxi = nums[i];
                mini = nums[i];
            }
        }

        if(prevMax > mini) return false;
        return true;
    }
};