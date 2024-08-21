class Solution {
public:
    bool isHappy(int n) {
        set<int> st;

        while(n != 1 && st.find(n) == st.end()){
            st.insert(n);

            int sum = 0;

            // calc the sum of squares of digits
            while(n > 0){
                int digit = n % 10;
                sum = sum + (digit * digit);
                n = n / 10;
            }

            n = sum;
        }
        
        return n == 1;
    }
};