class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        // initializing map
        unordered_map<int, int> degree;

        for(const auto& edge : edges){
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        // iterate in map
        for(auto &it : degree){
            if(it.second > 1){
                return it.first;
            }
        }
        return -1;
    }
};