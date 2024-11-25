class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for(auto& s : strs){

            vector<int> hash(26, 0);
            for(char c : s){
                hash[c - 'a']++;
            }

            // convert freq to string (key)
            string key = "";
            for(int count : hash){
                key += to_string(count) + ",";
            }

            // group anagram by key
            mpp[key].push_back(s);
        }

        vector<vector<string>> result;
        // iterate in map
        for(auto& it : mpp){
            result.push_back(it.second);
        }

        return result;
    }
};