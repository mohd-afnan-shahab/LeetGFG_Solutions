class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, k = n-1;
        while(j <= k){
            if(nums[j] == 1){
                j++;
            }
            else if(nums[j] == 0){
                swap(nums[j], nums[i]);
                i++;
                j++;
            }
            else {
                swap(nums[j], nums[k]);
                k--;
            }
        }
    }
};