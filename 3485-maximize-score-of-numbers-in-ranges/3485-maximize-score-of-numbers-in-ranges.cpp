class Solution {
public:
    bool canAchieve(int mid, vector<int>& start, int d){
        int n = start.size();

        long long prev = start[0];

        for (int i = 1; i < n; ++i) {
  
            long long next = max(prev + mid, (long long)start[i]);  // Ensure the next number is at least `mid` away
            
                if (next > start[i] + d) {
                    return false;
                }
            
            prev = next;
        }

        return true;
    }

    int maxPossibleScore(vector<int>& start, int d){
        int n = start.size();

        sort(start.begin(), start.end());

        long long low = 0, high = 2e9, answer = 0;
        while (low <= high) {
            long long mid = mid = low + (high - low) / 2;
            
            if (canAchieve(mid, start, d)) {
                answer = mid;  // Update the answer
                low = mid + 1;  // Try for a larger score
            } else {
                high = mid - 1;  // Try for a smaller score
            }
        }

        return answer;
    }
};