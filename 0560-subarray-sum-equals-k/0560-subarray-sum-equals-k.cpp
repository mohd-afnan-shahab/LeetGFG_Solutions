class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // unordered_map<int, int> mpp;
        // mpp[0] = 1;
        // int preSum=0;
        // int count=0;
        
        // for(int i = 0; i < nums.size(); i++){
        //     preSum = preSum + nums[i];

        //     int remove = preSum - k;
        //     count = count + mpp[remove];
        //     mpp[preSum]++;
        // }

        // return count;
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int presum = 0;
        int count = 0;

        for(int i = 0; i < n; i++) {
            presum += nums[i];
            int remove = presum - k;
            if(mpp.find(remove) != mpp.end()) {
                count += mpp[remove];
            }
            mpp[presum]++;
        }

        return count;
    }
};