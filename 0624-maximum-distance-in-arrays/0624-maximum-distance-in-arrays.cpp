class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minn = arrays[0].front();         // 1 from 1st array
        int maxx = arrays[0].back();        // 3 from 1st array
        int maxDistance = 0;

        for(int i = 1; i < arrays.size(); i++){
            int currMin = arrays[i].front();     //4 from 2nd array
            int currMax = arrays[i].back();    //5 from 2nd array

            maxDistance = max({maxDistance, abs(maxx - currMin), abs(minn - currMax)});

            maxx = max(maxx, currMax);
            minn = min(minn, currMin);
        }

        return maxDistance;
    }
};