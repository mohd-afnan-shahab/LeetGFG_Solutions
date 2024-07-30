class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int max_ele = *max_element(nums.begin(), nums.end());
        vector<int> hash(max_ele + 1, 0);

        for(int i = 0; i < nums.size(); i++){
            if (nums[i] <= max_ele) {
                hash[nums[i]] = 1;
            }
        }

        for(int i = 0; i <= max_ele; i++){
            if (hash[i] == 0){
                return i;
            }
        }

        return max_ele + 1;
    }
};
