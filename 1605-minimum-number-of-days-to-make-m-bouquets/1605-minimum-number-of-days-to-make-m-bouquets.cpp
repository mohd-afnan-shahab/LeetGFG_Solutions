class Solution {
public:

    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int count = 0, noofbouq = 0;

        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                count++;
            }
            else {
                noofbouq += (count/k);
                count = 0;
            }
        }
        noofbouq += (count/k);
        return noofbouq >= m;
    }

    int minDays(vector<int>& bloomDay, long long m, long long k) {
        long long n = bloomDay.size();
        long long val = (m * k);
        if(val > n) return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        long long low = mini, high = maxi;
        while(low <= high){
            long long mid = (low + high)/2;

            if(possible(bloomDay, mid, m, k)){
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return low;
    }
};