class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n);

        for(int i=0; i<n; i++){
            int j = (i + k) % n;
            result[j] = nums[i];
        }
        
        nums = result;
    }
};