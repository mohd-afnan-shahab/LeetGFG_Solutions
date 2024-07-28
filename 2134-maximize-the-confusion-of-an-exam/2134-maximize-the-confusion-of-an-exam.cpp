class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int countF = 0, countT = 0;
        int ans = 0;
        int n = answerKey.size();

        //sliding window template
        int l = 0, r = 0;
        while(r < n){
            if(answerKey[r] == 'T') countT++;
            else countF++;

            // because i need max length that's why i am using if otherwise use while.
            if(min(countT, countF) > k){
                if(answerKey[l] == 'T') countT--; 
                else countF--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};