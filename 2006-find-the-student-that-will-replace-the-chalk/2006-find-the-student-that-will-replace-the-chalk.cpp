class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalChalks = 0;
        for(const auto& ch : chalk){
            totalChalks = totalChalks + ch;
        }

        int remainingChalks = k % totalChalks;

        for(int i = 0; i < chalk.size(); i++){
            if(chalk[i] > remainingChalks) return i;
            remainingChalks = remainingChalks - chalk[i];
        }
        return -1;
    }
};