class Solution {
public:
    void setA(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] != 'O')
            return;
        board[x][y] = 'A';
        if (x > 0) setA(board, x - 1, y);
        if (x + 1 < board.size()) setA(board, x + 1, y);
        if (y > 0) setA(board, x, y - 1);
        if (y + 1 < board[0].size()) setA(board, x, y + 1);
    }
    
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;
        for (int i = 0; i < board.size(); ++i) {
            setA(board, i, 0);
            setA(board, i, board[0].size() - 1);
        }
        for (int i = 0; i < board[0].size(); ++i) {
            setA(board, 0, i);
            setA(board, board.size() - 1, i);
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') 
                    board[i][j] = 'X';
                else if (board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
    }
};