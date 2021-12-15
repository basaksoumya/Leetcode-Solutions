class Solution {
public:
    
    bool wordSearch(vector<vector<char>> &board,string word,int row,int col,int index) {
        
        if(row < board.size() && row >= 0 && col >= 0 && col < board[0].size()) {
            if(board[row][col] == word[index]) {
                board[row][col] = '0';
                if(index == word.size()-1)
                    return true;
                bool ans;
                ans = wordSearch(board,word,row+1,col,index+1);
                ans = ans || wordSearch(board,word,row-1,col,index+1);
                ans = ans || wordSearch(board,word,row,col+1,index+1);
                ans = ans || wordSearch(board,word,row,col-1,index+1);
                board[row][col] = word[index];
                return ans;
            }
            else
                return false;
        }
        return false;
    }
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(wordSearch(board,word,i,j,0)) {
                    return true;
                }
            }
        }
        return false;
    }
};