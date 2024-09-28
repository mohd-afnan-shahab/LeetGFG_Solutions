class Solution {
public:

    // TIME COMPLEXITY - O(n) and SPACE COMPLEXITY - O(1)
    int fib(int n) {

        if(n <= 1){
            return n;
        }
        int currentFib;
        int previousFib = 1;
        int secondPreviousFib = 0;

        for (int i = 2; i <= n; i++) {
            currentFib = previousFib + secondPreviousFib;
            secondPreviousFib = previousFib;
            previousFib = currentFib;
        }

        return currentFib;
    }
};
