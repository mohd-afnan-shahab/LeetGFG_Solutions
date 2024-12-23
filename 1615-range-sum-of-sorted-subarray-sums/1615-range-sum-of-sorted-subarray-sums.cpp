class Solution {
public:
    int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> newarray;

        
        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                newarray.push_back(sum);
            }
        }
        sort(newarray.begin(), newarray.end());

        int sumofnewarray = 0;
        for(int i = left - 1; i < right; i++){
            sumofnewarray =  (sumofnewarray + newarray[i]) % mod;
        }

        return sumofnewarray;
        
    }
};