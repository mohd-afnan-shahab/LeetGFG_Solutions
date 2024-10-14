class Solution {
public:
    // TIME COMPLEXITY - O(N + K log N) and SPACE COMPLEXITY - O(N)
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;

        priority_queue<int> pq(nums.begin(), nums.end());       // O(N)

        for(int i = 0; i < k; i++){
            int maxElement = pq.top();
            pq.pop();   // O(log N)

            score = score + maxElement;
            maxElement = ceil(maxElement / 3.0);

            pq.push(maxElement);    // O(log N)
        }

        return score;
    }
};