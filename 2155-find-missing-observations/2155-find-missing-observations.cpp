class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(); // Get the size of the observed rolls (m).
        int sum = mean * (n + m); // Calculate the total sum of all n + m rolls.

        // Subtract the sum of the observed rolls from the total sum.
        for(int i = 0; i < m; i++){
            sum = sum - rolls[i];
        }

        if(sum < n || sum > 6 * n) return {}; 

        vector<int> result(n, sum / n);
        
        int remainder = sum % n;

        // Distribute the remainder by adding 1 to the first 'remainder' elements.
        for(int i = 0; i < remainder; i++){
            result[i]++;
        }

        return result;
    }
};
