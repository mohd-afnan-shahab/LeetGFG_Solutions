class Solution {
public:
    // TIME COMPLEXITY - O(N) and SPACE COMPLEXITY - O(1)
    long long minimumSteps(string s) {
        int countOnes = 0;
        long long minSteps = 0;

        for(auto& ch : s){
            if(ch == '1'){
                countOnes++;
            }
            else if(ch == '0'){
                minSteps += countOnes;
            }
        }

        return minSteps;
    } 
};