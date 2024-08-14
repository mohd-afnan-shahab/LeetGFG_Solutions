class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i + 1]){
                nums[i] = nums[i]*2;
                nums[i + 1] = 0;
            }
        }

        vector<int> newArray;
        for(const auto& num : nums){
            if(num != 0){
                newArray.push_back(num);
            }
        }

        while(newArray.size() < n){
            newArray.push_back(0);
        }
        
        return newArray;
    }
};