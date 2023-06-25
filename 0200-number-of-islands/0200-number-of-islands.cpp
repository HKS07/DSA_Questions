class Solution {
    
public:
     void bfs( int r, int c, vector<vector<bool>> &vis, vector<vector<char>>& grid)
    {
        vis[r][c] = true;
        int ro = grid.size(), co = grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({r,c});
         
        while(!q.empty())
        {
//             int size = q.size();
            
            
//             for( int s = 0; s < size; ++s )
//             {
                int row = q.front().first, col = q.front().second;
                q.pop();
                
                //up
                if( (row - 1 >= 0) && grid[row-1][col] == '1' && vis[row-1][col] == false ) 
                {
                    cout<<"up"<<endl;
                    vis[row-1][col] = true;
                    q.push({row-1,col});
                }
                //down
                if( (row + 1 < ro) && grid[row+1][col] == '1' && vis[row+1][col] == false ) 
                {
                    cout<<"up"<<endl;
                    vis[row+1][col] = true;
                    q.push({row+1,col});
                }//left
                if( (col - 1 >= 0) && grid[row][col-1] == '1' && vis[row][col-1] == false ) 
                {
                    cout<<"up"<<endl;
                    vis[row][col-1] = true;
                    q.push({row,col-1});
                }//up
                if( (col + 1 < co) && grid[row][col+1] == '1' && vis[row][col+1] == false ) 
                {
                    cout<<"up"<<endl;
                    vis[row][col+1] = true;
                    q.push({row,col+1});
                }
            // }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size(), col = grid[0].size();
        
        vector<vector<bool>> vis( row, vector<bool> (col,false) );
     
        int count = 0;
        for( int i = 0; i < row; ++i )
        {
            for( int j = 0; j < col; ++j )
            {
               if( vis[i][j] == false && grid[i][j] == '1')
               {
                   count++;
                   
                   bfs( i, j, vis, grid );
               }
            }
        }
        
        return count;
    }
};