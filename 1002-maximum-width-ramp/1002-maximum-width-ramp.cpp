class Solution {
public:
    // TIME COMPLEXITY - O(N) and SPACE COMPLEXITY - O(N)
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxRight(n);
        maxRight[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 1; i--){
            maxRight[i] = max(maxRight[i + 1], nums[i]);
        }

        int i = 0;
        int j = 0;
        int ramp = 0;

        // traverse maxRight
        while(j < n){

            while(i < j && nums[i] > maxRight[j]) i++;

            ramp = max(ramp, j - i);
            j++;
        }

        return ramp;
    }
};