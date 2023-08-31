class Solution {
public:
    bool isValid( int r, int c, int n, int m )
    {
        return r >= 0 && c >= 0 && r < n && c < m; 
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n,vector<int> (n,0));
        queue<pair<int,pair<int,int>>> q;
        for( int i = 0; i < n; ++i )
        {
            for( int j = 0; j < m; ++j )
            {
                if(mat[i][j] == 0) 
                {
                    q.push({0,{i,j}});
                }
                else
                {
                    mat[i][j] = 1e9;
                }
            }
        }
        int delR[] = {0,-1,0,1};
        int delC[] = {-1,0,1,0};
        while( !q.empty() )
        {
            int dis = q.front().first, i = q.front().second.first, j = q.front().second.second;
            q.pop();
            
            for( int del = 0; del < 4; ++del )
            {
                
                int r = i + delR[del], c = j + delC[del];
                if( isValid(r,c,n,m) && mat[r][c] == 1e9 )
                {
                    // cout<<r<<" "<<c<<endl;
                    // cout<<dist[i][j]<<endl;
                    if( dis + 1 < mat[r][c] )
                    {
                        mat[r][c] = dis + 1;
                        q.push({mat[r][c],{r,c}});
                    }
                }
            }
        }
        
        return mat;
        
    }
};