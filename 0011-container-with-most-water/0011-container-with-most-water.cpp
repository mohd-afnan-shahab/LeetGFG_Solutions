class Solution {
public:
    int maxArea(vector<int>& height) {
        // int n = height.size();
        // int maxi = 0;

        // for(int i = 0; i < n; i++){
        //     for(int j = i + 1; j < n; j++){
        //         int area = (j - i) * min(height[i], height[j]);
        //         maxi = max(area, maxi);
        //     }
        // }
        // return maxi;

        int n = height.size();
        int maxi = 0;

        int l = 0;
        int h = n - 1;
        while(l < h){
            int area = (h - l) * min(height[l], height[h]);
            maxi = max(area, maxi);

            if(height[l] < height[h]){
                l++; 
            }
            else h--;

        }
        return maxi;
    }
};