class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        dist[0][0] = 0;

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{0,0}});

        int delR[] = {0,-1,0,1};
        int delC[] = {-1,0,1,0};
        while( !pq.empty() )
        {
            int routeTime = pq.top().first, i = pq.top().second.first, j = pq.top().second.second;
            pq.pop();
            for( int del = 0; del < 4; ++del )
            {
                int r = i + delR[del], c = j + delC[del];
                if( r >= 0 && c >= 0 && r < n && c < m )
                {
                    int routeTimeTillCurNode = max(abs(h[r][c] - h[i][j]) , routeTime);

                    if( routeTimeTillCurNode < dist[r][c] )
                    {
                        pq.push({routeTimeTillCurNode,{r,c}});
                        dist[r][c] = routeTimeTillCurNode;
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};