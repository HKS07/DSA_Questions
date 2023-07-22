class Solution {
public:
    int help( vector<int> &v)
    {
        int maxx = 0;
        stack<int> s; int n = v.size();
        for( int i = 0; i <= n; ++i )
        {
            while( !s.empty() && ( i == n ||  v[i] <= v[s.top()]))
            {
                
                int lb , rb = i-1;
                int ht = v[s.top()]; s.pop();
                if( s.empty() ) lb = 0;
                else lb = s.top() + 1;
                
                maxx = max( maxx, (rb-lb+1)*ht);
            }
            s.push(i);
        }
        return maxx;
    }


    int maximalRectangle(vector<vector<char>>& m) {
        int r = m.size(), c = m[0].size(), sol = 0;
        vector<int> v(c,0);
        
        for( int i = 0; i < r; ++i )
        {
            for( int j = 0; j < c; ++j )
            {
                v[j] = m[i][j] == '0'? 0: v[j] + 1; 
            }
            int a = help(v);
            sol = max( sol, a);
            
        }
        return sol;
    }
};