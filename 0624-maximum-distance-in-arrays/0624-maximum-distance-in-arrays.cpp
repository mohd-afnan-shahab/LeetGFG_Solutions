class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {

        int Min = arrays[0].front();
        int Max = arrays[0].back();

        int max_distance = 0;

        for(int i = 1; i < arrays.size(); i++){
            int currMin = arrays[i].front();
            int currMax = arrays[i].back();

            max_distance = max({max_distance, abs(Max - currMin), abs(Min - currMax)});

            Min = min(Min, currMin);
            Max = max(Max, currMax);
            
        }

        return max_distance;
    }
    
};