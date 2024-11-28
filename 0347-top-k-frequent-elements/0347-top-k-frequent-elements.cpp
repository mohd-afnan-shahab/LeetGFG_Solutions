class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;         // {ele, freq}
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        vector<pair<int, int>> vec;
        for(auto& it : mp){
            vec.push_back({it.first, it.second});
        }

        // sort vec based on freq in descending order.
        sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        });

        // take top k ele
        vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(vec[i].first);
        }

        return result;

    }
};