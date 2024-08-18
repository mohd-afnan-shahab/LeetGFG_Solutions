class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        long long prevA = energyDrinkA[0];
        long long prevB = energyDrinkB[0];
        
        for (int i = 1; i < n; ++i) {
            long long newA = max(prevA + (long long)energyDrinkA[i], prevB);
            long long newB = max(prevB + (long long)energyDrinkB[i], prevA);
            prevA = newA;
            prevB = newB;
        }
        
        return max(prevA, prevB);
    }
};
