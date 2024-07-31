class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);
        vector<int> pos, neg;
        
        // separate positive and negative numbers
        for(int i = 0; i < n; i++){
            if(nums[i] >= 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }

        // rearrange positive at even indices and negative at odd indices..
        for(int i = 0; i < n/2; i++){
            result[2 * i] = pos[i];
            result[2 * i + 1] = neg[i];
        }
        return result;
    }
};