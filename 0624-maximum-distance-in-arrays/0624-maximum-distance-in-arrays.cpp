class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int globalMin = arrays[0].front();         // 1 from 1st array
        int globalMax = arrays[0].back();          // 3 from 1st array
        int maxDist = 0;

        for(int i = 1; i < arrays.size(); i++){
            int currentMin = arrays[i].front();    // 4 from 2nd array
            int currentMax = arrays[i].back();     // 5 from 2nd array

            maxDist = max({maxDist, abs(globalMax - currentMin), abs(globalMin - currentMax)});

            globalMax = max(globalMax, currentMax);
            globalMin = min(globalMin, currentMin);
        }

        return maxDist;
    }
};
