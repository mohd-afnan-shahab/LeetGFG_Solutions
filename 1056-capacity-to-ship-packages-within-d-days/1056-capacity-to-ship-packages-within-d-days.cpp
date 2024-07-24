class Solution {
public:

    int func(vector<int>& weights, int mid){
        int days = 1;
        int load = 0;
        
        for(int i = 0; i < weights.size(); i++){
            if(load + weights[i] > mid){
                days += 1;
                load = weights[i];
            }
            else
                load += weights[i];
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxi = *max_element(weights.begin(), weights.end());

        int sumElements = 0;
        for(auto num:weights){
            sumElements += num;
        }

        int low = maxi, high = sumElements;
        while(low <= high){
            int mid = (low + high)/2;

            int daysReq = func(weights, mid);
            if(daysReq <= days){
                high = mid - 1;
            }
            else
                low = mid + 1;

        }
        return low;
    }
};