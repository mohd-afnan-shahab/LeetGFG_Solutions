class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftArr(n);
        leftArr[0] = 1;
        for(int i = 1; i < n; i++){
            leftArr[i] = nums[i-1] * leftArr[i-1];
        }

        vector<int> rightArr(n);
        rightArr[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            rightArr[i] = nums[i+1] * rightArr[i+1];
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = leftArr[i] * rightArr[i];
        }

        return ans;
    }
};