class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        double totalwaittime = 0;
        int currtime         = 0;

        for(auto &vec : customers){
            int arrivaltime = vec[0];
            int cooktime    = vec[1];

            if(currtime < arrivaltime){
                currtime = arrivaltime;
            }

            int waittime = (currtime + cooktime) - arrivaltime;
            totalwaittime += waittime;

            currtime = currtime + cooktime;
        }

        return totalwaittime/n;
    }
};