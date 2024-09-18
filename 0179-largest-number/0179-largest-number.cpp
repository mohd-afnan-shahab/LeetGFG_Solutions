class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        auto customSort = [](int& a, int& b) {
            string s1 = to_string(a);
            string s2 = to_string(b);

            if(s1 + s2 > s2 + s1){
                return true;
            }

            return false;
        };

        sort(nums.begin(), nums.end(), customSort);

        string str = "";

        for(auto num : nums){
            str = str + to_string(num);
        }

        if(str[0] == '0'){
            return "0";
        }
        return str;
    }
};