class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int idx = 0;

        for(auto& num : nums){
            
            if(idx < 2 || nums[idx - 2] != num){
                nums[idx] = num;
                idx++;
            }
        }

        return idx;
    }
};