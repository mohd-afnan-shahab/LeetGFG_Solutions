class Solution {
public:

    bool possibleToDistribute(int maxProducts, vector<int>& quan, int n) {
        int requiredStores = 0;

        for (int q : quan) {
            // Calculate the number of stores required for this type of product
            // with each store holding at most 'maxProducts'.
            requiredStores += (q + maxProducts - 1) / maxProducts;

            // If the required stores exceed available stores, return false.
            if (requiredStores > n) {
                return false;
            }
        }

        return true;
    }


    int minimizedMaximum(int n, vector<int>& quan) {
        int m = quan.size();

        int l = 1, r = *max_element(quan.begin(), quan.end());

        int ans = 0;
        while(l <= r){
            int mid = (l+r)/2;

            if(possibleToDistribute(mid, quan, n)){
                ans = mid;
                r = mid - 1;    // checking of min values..
            }
            else{
                l = mid + 1;    // this is not valid condition..
            }
        }
        
        return ans;
    }
};