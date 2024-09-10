class Solution {
public:

    // int findCenter(vector<vector<int>>& edges) {
        
    //     // initializing map
    //     unordered_map<int, int> degree;

    //     for(const auto& edge : edges){
    //         degree[edge[0]]++;
    //         degree[edge[1]]++;
    //     }

    //     // iterate in map
    //     for(auto &it : degree){
    //         if(it.second > 1){
    //             return it.first;
    //         }
    //     }
    //     return -1;
    // }

    // OPTIMISED APPROACH 

    int findCenter(vector<vector<int>>& edges) {

        // choose edge 0
        vector<int> first = edges[0];   // {a, b}
        vector<int> second = edges[1];  // {c, a}

        // check if first[0] is the center node
        if(first[0] == second[0] || first[0] == second[1]){
            return first[0];
        }
        
        // otherwise, first[1] is the center node
        return first[1];
    }

};