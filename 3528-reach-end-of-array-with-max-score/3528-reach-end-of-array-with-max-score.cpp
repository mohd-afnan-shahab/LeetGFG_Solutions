class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;

        int low = nums[0], j = 0;

        for(int i = 1; i < n - 1; i++){
            if(nums[i] > nums[j]){
                ans += low * 1LL * (i - j);
                low = nums[i];
                j = i;
            }
        }

        ans += low * 1LL * (n - 1 - j);
        return ans;
    }
};