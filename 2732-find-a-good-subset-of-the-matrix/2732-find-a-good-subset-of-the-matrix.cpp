class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> bitToDec(32, -1 );// to represent each row into as a decimal
        vector<int> sol;
        // converting row to decimal
        for( int row = 0; row < grid.size(); ++row )
        {
            reverse( grid[row].begin(), grid[row].end() );
            int num = 0;
            for( int col = 0; col < grid[row].size(); ++col )
            {
                num += grid[row][col] * ( 1<<col );
            }
            bitToDec[num] = row;
        }
        if( bitToDec[0] != -1 )
        {
            // there exist a row with all value zero
            return {bitToDec[0]};
        }
        for( int i = 1; i < 32; ++i )
        {
            for( int j = 1; j < 32; ++j )
            {
                if( (( i & j ) == 0) && bitToDec[i] != -1 && bitToDec[j] != -1)
                {
                    // i and j which are decimal value of row, are they giving bitwise and 0
                    // if yes that means we have two rows in which each column has either bot 
                    // zero or one zero and one one
                    // else not a such condition 
                    sol.push_back(bitToDec[i]);
                    sol.push_back(bitToDec[j]);
                    
                }
                if(sol.size() > 0 ) break;
            }
            if(sol.size() > 0 ) break;
        }
        sort(sol.begin(),sol.end());
        return sol;
    }
};