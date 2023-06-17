class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        
        long long sum = 0;
        int takenRow = 0, takenCol = 0;
        vector<bool> row(n,false), col(n,false);
        for( int i = queries.size() - 1;  i >= 0; --i )
        {
            int type = queries[i][0], idx = queries[i][1], val = queries[i][2];
            
            //row
            if( type == 0 && !row[idx] )
            {
                sum += (long long)(val * ( n - takenCol ));
                takenRow++;
                row[idx] = true;
            }
            else if( type == 1 && !col[idx])  // col
            {
                sum += (long long)(val * ( n - takenRow ));
                takenCol++;
                col[idx] = true;
            }
        }
        return sum;
    }
};