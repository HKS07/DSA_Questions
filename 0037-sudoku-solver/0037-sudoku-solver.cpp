class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
         solve(board);
    }
    bool solve( vector<vector<char>> &b )
    {
        
        for( int i = 0; i < 9; ++i )
        {
            for( int j = 0; j < 9; ++j )
            {
                if( b[i][j] == '.' )
                {
                    for( char c = '1'; c <= '9'; ++c )
                    {
                        if( isval(i,j,c,b) )
                        {
                            b[i][j] = c;

                            if( solve(b) == true ) return true;
                            else b[i][j] = '.';
                        }
                    }
                return false;
                }
            }
        }
        return true;
    }
    
    bool isval( int row, int col, char c, vector<vector<char>> &b)
    {
        for( int i = 0; i < 9; ++i )
        {
            if( b[i][col] == c) return false;
            if( b[row][i] == c ) return false;
            if( b[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
        }
        return true;
    }
    
};