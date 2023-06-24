class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==0) return image;
        int row = image.size(), col = image[0].size();
        queue<pair<int,int>> q; q.push({sr,sc}); 
        vector<vector<int>> vis(row, vector<int> (col,-1));
        int pix = image[sr][sc];
        while( !q.empty() )
        {
            int size = q.size();
            
            for( int i = 0; i < size; ++i )
            {
                int r = q.front().first, c = q.front().second; q.pop();
                
                //up
                if( r - 1 >= 0 && image[r-1][c] == pix && vis[r-1][c] == -1 )
                {
                    vis[r-1][c] = 1;
                    q.push({r-1,c});
                    image[r-1][c] = color;
                }
                //down
                if( r + 1 < row && image[r+1][c] == pix && vis[r + 1][c] == -1 )
                {
                    vis[r + 1][c] = 1;
                    q.push({r + 1,c});
                    image[r+1][c] = color;
                }
                //left
                if( c - 1 >= 0 && image[r][c-1] == pix && vis[r][c-1] == -1 )
                {
                    vis[r][c-1] = 1;
                    q.push({r,c-1});
                    image[r][c-1] = color;
                }
                //right
                if( c + 1 < col && image[r][c+1] == pix && vis[r][c+1] == -1 )
                {
                    vis[r][c+1] = 1;
                    q.push({r,c+1});
                    image[r][c+1] = color;
                }
            }
        }
        image[sr][sc] = color;
        return image;
    }
};