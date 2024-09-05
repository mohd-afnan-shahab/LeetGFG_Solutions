class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (n + m);

        for(int i = 0; i < m; i++){
            sum = sum - rolls[i];
        }

        if(sum < n || sum > 6 * n) return {};

        vector<int> result(n, sum/n);
        
        int remainder = sum % n;

        for(int i = 0; i < remainder; i++){
            result[i]++;
        }
        return result;
    }
};