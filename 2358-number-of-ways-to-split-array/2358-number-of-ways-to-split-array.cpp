class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        long long leftSum = 0, rightSum = 0;
        int split = 0;
        for(int i = 0; i < n-1; i++){
            leftSum += nums[i];
            rightSum = sum - leftSum;

            if(leftSum >= rightSum){
                split++;
            }
        }

        return split;
    }
};