class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> ans(k, 0);

        // inc the counter of remainders
        for(auto &num : arr){
            int rem = (num % k + k) % k;    // to handle -ve arr[i]
            ans[rem]++;
        }

        // edge case for 0th counter, if not even then false
        if(ans[0] % 2 != 0){
            return false;
        }

        // iterate in ans vector till k/2
        for(int i = 1; i <= k / 2; i++){
            int complement = k - i;

            if(ans[complement] != ans[i]) return false;
        }

        return true;
    }
};