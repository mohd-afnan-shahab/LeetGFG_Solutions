class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        for(int ope = 0; ope < k; ope++){
            int mini = INT_MAX;
            int index = -1;

            // find the min value
            for(int i = 0; i < n; i++){
                if(nums[i] < mini){
                    mini = nums[i];
                    index = i;
                }
            }

            nums[index] = nums[index] * multiplier;
        }
        return nums;
    }
};