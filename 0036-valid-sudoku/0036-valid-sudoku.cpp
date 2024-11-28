class Solution {
public:

    bool validBox(vector<vector<char>>& board,  int sr, int er, int sc, int ec){
        // 3* 3
        unordered_set<char> st;
        for(int i = sr; i <= er; i++){
            for(int j = sc; j <= ec; j++){

                if(board[i][j] == '.') continue;

                if(st.find(board[i][j]) != st.end()){
                    return false;
                }

                st.insert(board[i][j]);
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        //1. validate rows
        for(int row = 0; row < 9; row++){
            unordered_set<char> st;
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.') continue;

                if(st.find(board[row][col]) != st.end()){
                    return false;
                }

                st.insert(board[row][col]);
            }
        }


        //2. validate cols
        for(int col = 0; col < 9; col++){
            unordered_set<char> st;
            for(int row = 0; row < 9; row++){
                if(board[row][col] == '.') continue;

                if(st.find(board[row][col]) != st.end()){
                    return false;
                }

                st.insert(board[row][col]);
            }
        }


        //3. validate sub boxes.
        for(int Sr = 0; Sr < 9; Sr += 3){
            int Er = Sr + 2;

            for(int Sc = 0; Sc < 9; Sc += 3){
                int Ec = Sc + 2;

                if(!validBox(board, Sr, Er, Sc, Ec)){
                    return false;
                }
            }
        }

        return true;
    }
};