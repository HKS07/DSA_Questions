class Solution {
public:
    int delR[4] = {0,-1,0,1};
    int delC[4] = {-1,0,1,0};
    void safeMat( vector<vector<int>> &g, vector<vector<int>> &safe )
    {
        int n = g.size();
        queue<pair<int,int>> q;
        for( int i = 0; i < n; ++i )
            for( int j = 0; j < n; ++j )
                if( g[i][j] == 1 )
                    {safe[i][j] = 0;q.push({i,j});}
        
       while( !q.empty() )
       {
           int r = q.front().first, c = q.front().second, curDis = safe[r][c];
           q.pop();
           for( int i = 0; i < 4; ++i )
           {
               int row = r + delR[i], col = c + delC[i];
               if( row >= 0 && col >= 0 && row < n && col < n )
               {
                   if( safe[row][col] > curDis + 1 )
                   {
                       q.push({row,col});
                       safe[row][col] = curDis + 1;
                   }
               }
           }
       }
        
        // for( int i = 0; i < n; ++i )
        //  {   for( int j = 0; j < n; ++j )
        //     {
        //         cout<<safe[i][j]<<' ';
        //     }
        // cout<<endl;}
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if( n == 1 )
        {
            if( grid[0][0] == 1 ) return 0;
            
        }
        vector<vector<int>> safe(n, vector<int> (n,1e9)), dist(n,vector<int> (n, -1e9));
        safeMat(grid,safe);
        
        
        // priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({safe[0][0], {0,0}});
        
        while( !pq.empty() )
        {
            int parSd = pq.top().first, r = pq.top().second.first, c = pq.top().second.second;
            pq.pop();
            
            for( int del = 0; del < 4; ++del )
           {
               int row = r + delR[del], col = c + delC[del];
               if( row >= 0 && col >= 0 && row < n && col < n )
               {
                   int curSd = min(parSd, safe[row][col]);
                   if( dist[row][col] < curSd )
                   {
                       pq.push({curSd, {row,col}});
                       dist[row][col] = curSd;
                   }
               }
           }
        }
        return dist[n-1][n-1];
    }
};