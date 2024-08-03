class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int, unordered_map<int,int>> mpp;

        for(auto &p : pick){
            int player = p[0];
            int color = p[1];

            mpp[player][color]++;
        }

        int winCnt = 0;
        for(auto &it : mpp){
            int playerId = it.first;
           
            for(auto &colorCnt : it.second){
                if(colorCnt.second > playerId){
                    winCnt++;
                    break;
                }
            }
        }
        return winCnt;
    }
};