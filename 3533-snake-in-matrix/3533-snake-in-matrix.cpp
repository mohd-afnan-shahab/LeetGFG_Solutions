class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0;
        int y = 0;

        for(const auto& command : commands){
            if(command == "UP"){
                if(x == 0){
                    x = 0;
                }
                else {
                    x = x - 1;
                }
            }

            else if(command == "DOWN"){
                if(x == n - 1){
                    x = n - 1;
                }
                else{
                    x = x + 1;
                }
            }

            else if(command == "RIGHT"){
                if(y == n - 1){
                    y = n - 1;
                }
                else{
                    y = y + 1;
                }
            }

            else if(command == "LEFT"){
                if(y == 0){
                    y = 0;
                }
                else{
                    y = y - 1;
                }
            }
        }

        return (x * n) + y;
    }
};