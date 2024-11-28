class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        //1. store ele and freq in mp
        unordered_map<int, int> mp;
        for(int& num : nums){
            mp[num]++;                      // O(n)
        }

        //2.define min-heap
        priority_queue<P, vector<P>, greater<P>> p;             // min-heap

        //3. take out element from map and insert them into min-heap
        for(auto& it : mp){
            int value = it.first;
            int freq = it.second;

            p.push({freq, value});              // because min-heap will get designed based on freq.

            if(p.size() > k){
                p.pop();
            }
        }

        //4. take out top k elements from min-heap and push them into ans vector
        vector<int> ans;
        while(!p.empty()){
            ans.push_back(p.top().second);
            p.pop();
        }

        return ans;
    }
};