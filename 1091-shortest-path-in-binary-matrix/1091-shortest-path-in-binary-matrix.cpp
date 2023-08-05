class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& mx) {
        
        int n = mx.size(), m = mx[0].size();
        pair<int, int> src = {0,0}, dest = {n-1,m-1};
        // if( src.first == dest.first && src.second == dest.second  ) 
        // {
        //     if( mx[src.first][src.second] == 1 ) return 0;
        //     else return -1;
        // }
        if( mx[src.first][src.second] !=0 ) return -1;
        if( mx[dest.first][dest.second] !=0 ) return -1;
        
        vector<vector<int>> dist(n, vector<int> (m, 1e8));
        dist[src.first][src.second] = 1;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > q;
        q.push({1,{src.first,src.second}});

        int delR[4] = {0,-1,0,1};
        int delC[4] = {-1,0,1,0};
        while( !q.empty() )
        {
            int dis = q.top().first, i = q.top().second.first, j = q.top().second.second;
            q.pop();

            for( int row = -1; row <= 1; ++ row  )
            {
                for( int col = -1; col <= 1; ++col )
                {
                    int r  = i + row, c = j + col;

                    if( r >= 0 && r < n && c >= 0 && c < m && mx[r][c] == 0 && dis + 1 < dist[r][c] )
                    {
                        dist[r][c] = dis + 1;
                        q.push({dis+1,{r,c}});
                    }
                }
            }

        }
        return dist[dest.first][dest.second] == 1e8 ? -1:dist[dest.first][dest.second];
    }
};