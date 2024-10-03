class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        // calc total sum
        int sum = 0;
        for(auto& num : nums){
            sum = (sum + num) % p;      // (a+b)%p = (a%p + b%p)%p
        }

        int target = sum % p;
        if(target == 0) return 0;

        unordered_map<int, int> mp;     // it will store prev sum%p

        mp[0] = -1;
        int curr = 0;

        int minLength = n; 
        for(int j = 0; j < n; j++){
            curr = (curr + nums[j]) % p;

            int prev = (curr - target + p) % p;

            if(mp.find(prev) != mp.end()){
                minLength = min(minLength, j - mp[prev]);
            }

            mp[curr] = j;
        }

        return minLength == n ? -1 : minLength;
    }
};