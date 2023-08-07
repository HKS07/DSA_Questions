class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        vector<vector<int>> dist(n, vector<int> (n,1e9));
        for(auto e: edges)
        {
            int u = e[0], v= e[1], wt = e[2];
            dist[u][v] = dist[v][u] = wt;
            
        }
        for( int i = 0;i < n; ++i ) dist[i][i] = 0;
        
        for( int via = 0; via < n; ++via )
        {
            for( int i = 0; i < n; ++i )
            {
                for( int j = 0; j < n; ++ j )
                {
                    if( dist[i][via] != 1e9 && dist[via][j] != 1e9 )
                    dist[i][j] = min( dist[i][j], dist[i][via] + dist[via][j] );
                }
            }
        }
        
        int maxCount = n, city = -1;
        for( int i = 0; i < n; ++i )
            {
                 int count = 0;
                for( int j = 0; j < n; ++ j )
                {
                    // cout<<dist[i][j]<<" ";
                    if(dist[i][j] <= th )
                    {
                        count++;
                    }
                }
            // cout<<"th "<< count <<"maxcount: "<<maxCount<<endl;
            
                if( count <= maxCount )
                {
                    maxCount = count;
                    city = max(city,i);
                }
            }
        return city;
    }
};