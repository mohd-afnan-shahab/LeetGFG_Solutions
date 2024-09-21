class Solution {
public:

    // TIME COMPLEXITY - O(N) and SPACE COMPLEXITY - O(log n)
    void solveFurther(int currNum, int n, vector<int>& result){

        if(currNum > n) return;

        result.push_back(currNum);

        // further explore by appending
        for(int append = 0; append <= 9; append++){
            
            int newNum = (currNum * 10) + append;

            if(newNum > n) return;

            solveFurther(newNum, n, result);
        }
    }
    vector<int> lexicalOrder(int n) {
        
        vector<int> result;

        // start from 1 and perform DFS
        for(int start = 1; start <= 9; start++){
            solveFurther(start, n, result);
        }

        return result;
    }
};