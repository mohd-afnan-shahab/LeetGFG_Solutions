class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = 0;
        int sum = 0;
        int minLen = 1e9;

        while(r < n){

            sum += nums[r];

            // shrink the window
            while(r < n && sum >= target){
                minLen = min(minLen, r - l + 1);
                sum = sum - nums[l];
                l++;
            }

            r++;

        }

        if(minLen == 1e9) return 0;
        else return minLen;
    }
};