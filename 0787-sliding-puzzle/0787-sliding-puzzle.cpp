class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for(int i =  0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                start += to_string(board[i][j]);
            }
        }

        string target = "123450";
        queue<string> q;
        q.push(start);

        unordered_map<int, vector<int>> mp;        // [ idxofzero, {can-swap-with-idx} ]
        mp[0] = {1, 3};
        mp[1] = {0, 2, 4};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {1, 3, 5};
        mp[5] = {2, 4};

        unordered_set<string> visited;
        visited.insert(start);

        int levels = 0;     // least moves
        while(!q.empty()){

            int n = q.size();

            while(n--){
                string curr = q.front();
                q.pop();

                if(curr == target) return levels;

                int indexOfZero = curr.find('0');
                
                for(int swapIndex : mp[indexOfZero]){
                    string newState = curr;
                    swap(newState[indexOfZero], newState[swapIndex]);

                    if(visited.find(newState) == visited.end()){
                        q.push(newState);
                        visited.insert(newState);
                    }
                }
            }

            levels++;
        }

        return -1;
    }
};