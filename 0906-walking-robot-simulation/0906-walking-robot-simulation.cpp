class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for(vector<int>& obs : obstacles){
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(key);
        }

        int x = 0;
        int y = 0;
        int maxDistance = 0;

        pair<int, int> direction = {0, 1};  // north

        for(int i = 0; i < commands.size(); i++){
            
            // turn left (west)
            if(commands[i] == -2){
                direction = {-direction.second, direction.first};
            }

            // turn right (east)
            else if(commands[i] == -1){
                direction = {direction.second, -direction.first};
            }

            // move some steps
            else {
                for(int step = 0; step < commands[i]; step++){
                    int newX = x + direction.first;
                    int newY = y + direction.second;

                    string nextKey = to_string(newX) + "_" + to_string(newY);
                    
                    // If there's an obstacle at the new position, stop moving
                    if(st.find(nextKey) != st.end()){
                        break;
                    }

                    // Update position
                    x = newX;
                    y = newY;
                }
            }
            maxDistance = max(maxDistance, x*x + y*y);
        }
        return maxDistance;
    }
};