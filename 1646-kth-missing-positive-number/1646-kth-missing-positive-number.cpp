class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int low =0, high = n - 1;
        while(low <= high){
            int mid = (low + high)/2;

            int missing = arr[mid] - (mid + 1);   //7 - 4 = 3

            if(missing < k) low = mid + 1;
            else high = mid - 1;
        }
        // return (high + 1 + k);
        return low + k;
    }
};