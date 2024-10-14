class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;

        priority_queue<int> pq(nums.begin(), nums.end());

        for(int i = 0; i < k; i++){
            int maxElement = pq.top();
            pq.pop();   // log N

            score = score + maxElement;
            maxElement = ceil(maxElement / 3.0);

            pq.push(maxElement);
        }

        return score;
    }
};