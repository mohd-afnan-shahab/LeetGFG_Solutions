class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        string res = "";

        while(!pq.empty()){
            int currCount = pq.top().first;
            char currChar = pq.top().second; // Changed to char
            pq.pop();

            if(res.size() >= 2 && res[res.size() - 1] == currChar && res[res.size() - 2] == currChar){

                if(pq.empty()) break;

                int nextCount = pq.top().first;
                char nextChar = pq.top().second; // Changed to char
                pq.pop();

                res.push_back(nextChar);  
                nextCount--;

                if(nextCount > 0) pq.push({nextCount, nextChar});
            } else {
                currCount--;
                res.push_back(currChar);
            }

            if(currCount > 0) pq.push({currCount, currChar}); // Corrected pq.push_back to pq.push
        } 

        return res; // Corrected 'result' to 'res'
    }
};
