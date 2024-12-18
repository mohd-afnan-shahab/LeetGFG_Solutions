class Solution {
public:

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // int stops[1001] = {};

        // for(auto t : trips){
        //     stops[t[1]] += t[0];
        //     stops[t[2]] -= t[0];
        // }

        // for(auto i = 0; capacity >= 0 && i < 1001; i++){
        //     capacity = capacity - stops[i];
        // }

        // return capacity >= 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0; i < trips.size(); i++){
            pq.push({trips[i][1], trips[i][0]});
            pq.push({trips[i][2], -trips[i][0]});
        }

        int onBoard = 0;
        while(!pq.empty()){
            onBoard += pq.top().second;
            pq.pop();
            
            if(onBoard > capacity) return false;
        }

        return true;
    }
};