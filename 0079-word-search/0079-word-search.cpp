class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length() > (board.size() * board[0].size()))
            return false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(helper(board,word,0,i,j))
                    return true;
            }
        }
        return false;
    }
    
    bool helper(vector<vector<char>>& board, string word, int idx, int i, int j){
        bool result = false;
        char ch = board[i][j];
        if(ch != word[idx])
            return result;
        if(word.length() == idx+1)
            return true;
        board[i][j] = '!';
        if(i > 0 && helper(board,word, idx+1, i-1, j))
           result = true;
        if(i < board.size() - 1  && helper(board,word, idx+1, i+1, j))
           result = true;
        if(j > 0 && helper(board,word,idx+1, i, j -1))
           result = true;
        if(j < board[0].size() - 1 && helper(board, word, idx+1, i, j+1))
           result = true;
        board[i][j] = ch;
        return result;
    }
};