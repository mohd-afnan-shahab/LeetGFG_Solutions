class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        vector<int> chairs(n, -1);
        int arrivalOfTargetFriend = times[targetFriend][0];

        sort(times.begin(), times.end());       // Sorting times by arrival times
        
        // Iterate through the friends
        for(auto& time : times){
            int arrival = time[0];
            int leaving = time[1];

            // Find an empty chair or a chair that becomes available
            for(int i = 0; i < n; i++){
                if(arrival >= chairs[i]){
                    chairs[i] = leaving;
                    if(arrival == arrivalOfTargetFriend){
                        return i;
                    } 
                    break;
                }
            }
        }
        return -1;
    } 
}; 