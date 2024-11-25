class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++){
            
            int complement = target - nums[i];

            // If complement found in map, return its index and current index
            if(mpp.find(complement) != mpp.end()){
                return {mpp[complement], i};
            }

            mpp[nums[i]] = i;
        }

        return {};
    }
};