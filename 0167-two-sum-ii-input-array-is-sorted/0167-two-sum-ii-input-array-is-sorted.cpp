class Solution {
public:
    int binarySearch(vector<int>& numbers, int complement, int start, int end){
        
        int low = start, high = end;

        while(low <= high){
            int mid = (low + high)/2;
            if(numbers[mid] == complement){
                return mid;
            }
            else if(numbers[mid] > complement){
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for(int i = 0; i < n; i++){
            int complement = target - numbers[i];

            // search for complement in given subarray only..
            int j = binarySearch(numbers, complement, i + 1, n - 1);

            if(j != -1){
                return {i + 1, j + 1};
            }
        }

        return {};
    }

};